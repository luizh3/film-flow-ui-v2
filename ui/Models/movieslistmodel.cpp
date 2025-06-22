#include "movieslistmodel.h"

#include <core/entities/searchmovies.h>
#include <core/helper/taskrunhelper.h>
#include <core/entities/movieinformation.h>
#include <core/controller/sectioncontroller.h>
#include <core/network/request/sectionrequest.h>

namespace {
constexpr int NR_MOVIES_BY_PAGE = 20;
}

MoviesListModel::~MoviesListModel()
{
    delete _sectionRequest;
    delete _sectionController;
}

MoviesListModel::MoviesListModel() :
    _sectionRequest{ new SectionRequest()},
    _sectionController{ new SectionController() },
    _isFetching{false},
    _fechingMoviesCard({}),
    _moviesCard({}){
}

int MoviesListModel::rowCount( const QModelIndex &parent ) const {
    return _moviesCard.count();
}

QVariant MoviesListModel::data( const QModelIndex &index, int role ) const {


    if ( !index.isValid() ) {
        return QVariant();
    }

    const int row = index.row();

    switch ( role ) {
    case Title:
        return _moviesCard.at( row )->title;
    case PosterUrl: {
        return _moviesCard.at( row )->posterUrl;
    }
    case Average: {
        return _moviesCard.at( row )->average;
    }
    case IsLoading: {
        return _moviesCard.at( row )->isLoading;
    }
    default:
        return QVariant();
    }

}

void MoviesListModel::fetchMore( const QModelIndex &parent ) {

    if (parent.isValid() || _isFetching) {
        return;
    }

    _isFetching = true;

    _sectionRequest->setPage( _sectionRequest->page() + 1 );

    beginInsertRows(QModelIndex(), _moviesCard.length(), _moviesCard.length() + NR_MOVIES_BY_PAGE - 1);

    ajustFechingCardsMovie( NR_MOVIES_BY_PAGE );

    endInsertRows();

    QFutureWatcher<SearchMovies*>* future = TaskRunHelper::async<SearchMovies*>(
    [&]() {
        return _sectionController->find( *_sectionRequest );
    });

    QObject::connect( future, &QFutureWatcher<SearchMovies*>::finished, this, [this, future]() {

        if ( future->isFinished() && !future->isCanceled() ) {

            std::unique_ptr<SearchMovies> searchMovies( future->result() );

            updateCardsMovie( _fechingMoviesCard, searchMovies->movies() );

            emit dataChanged(index(_moviesCard.length() - NR_MOVIES_BY_PAGE), index(_moviesCard.length() - 1));

            _isFetching = false;
        }

        future->deleteLater();
    } );
}

bool MoviesListModel::canFetchMore( const QModelIndex& parent) const {

    if (parent.isValid()) {
        return false;
    }

    return !_isFetching;
}

QHash<int, QByteArray> MoviesListModel::roleNames() const {

    static QHash<int, QByteArray> mapping {
        { Title, "title" },
        { PosterUrl, "posterUrl"},
        { Average, "average"},
        { IsLoading, "isLoading"}
    };

    return mapping;

}

void MoviesListModel::ajustFechingCardsMovie( const int nrCards ) {

    _fechingMoviesCard.clear();

    std::generate_n(std::back_inserter(_fechingMoviesCard), NR_MOVIES_BY_PAGE, []() {
        return new CardMovie();
    });

    _moviesCard.append( _fechingMoviesCard );

}

void MoviesListModel::updateCardsMovie( const QList<CardMovie*>& cardsMovie, const QList<MovieInformation*>& moviesInformation) const
{
    for( int index = 0; index < cardsMovie.length(); index++ ) {
        updateCardMovie( cardsMovie[index], moviesInformation[index] );
    }
}

void MoviesListModel::updateCardMovie(CardMovie *movieCard, const MovieInformation *movieInformation) const
{
    movieCard->average = movieInformation->average();
    movieCard->posterUrl = movieInformation->posterUrl();
    movieCard->title = movieInformation->title();
    movieCard->isLoading = false;
}


void MoviesListModel::setTpProgram( TypeProgramEnum newTpProgram )
{

    if( !_sectionRequest ){
        return;
    }

    _sectionRequest->setTpProgram( newTpProgram );

}

void MoviesListModel::setKey(const QString &newKey)
{

    if( !_sectionRequest ){
        return;
    }

    _sectionRequest->setKey( newKey );

}

MoviesListModel::CardMovie::CardMovie() :
    title{QStringLiteral("")},
    posterUrl{QStringLiteral("")},
    average{0.00},
    isLoading{true}{}
