#include "movieslistmodel.h"

#include <core/entities/searchmovies.h>
#include <core/helper/taskrunhelper.h>
#include <core/entities/movieinformation.h>
#include <core/controller/sectioncontroller.h>
#include <core/network/request/sectionrequest.h>

#include "helper/cardsfetchhelper.h"

namespace {
constexpr int NR_MOVIES_BY_PAGE = 20;
}

MoviesListModel::~MoviesListModel()
{
    _sectionController->cancel();

    _sectionController->deleteLater();

    delete _sectionRequest;

    qDeleteAll(_moviesCard);
}

MoviesListModel::MoviesListModel()
    : _sectionRequest{new SectionRequest()}
    , _sectionController{new SectionController()}
    , _isFetching{false}
    , _fechingMoviesCard{}
    , _moviesCard{}
{}

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
    case Id: {
        return _moviesCard.at(row)->id;
    }
    case TpProgram: {
        return QVariant::fromValue(_moviesCard.at(row)->tpProgram);
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

    CardFetchHelper::appendFetchingCards<CardMovie>(
        _moviesCard,
        _fechingMoviesCard,
        NR_MOVIES_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new CardMovie(); });

    QFutureWatcher<SearchMovies*>* future = TaskRunHelper::async<SearchMovies*>(
    [&]() {
        return _sectionController->find( *_sectionRequest );
    });

    QObject::connect(future, &QFutureWatcher<SearchMovies *>::finished, this, [this, future]() {
        onFetchEnded(future);
    });
}

bool MoviesListModel::canFetchMore( const QModelIndex& parent) const {

    if (parent.isValid()) {
        return false;
    }

    return !_isFetching;
}

QHash<int, QByteArray> MoviesListModel::roleNames() const {
    static QHash<int, QByteArray> mapping{{Title, "title"},
                                          {PosterUrl, "posterUrl"},
                                          {Average, "average"},
                                          {IsLoading, "isLoading"},
                                          {Id, "id"},
                                          {TpProgram, "tpProgram"}};

    return mapping;

}

void MoviesListModel::updateCardsMovie(const QList<CardMovie *> &cardsMovie,
                                       const QList<MovieInformation *> &moviesInformation)
{
    CardFetchHelper::updateCards<CardMovie, MovieInformation>(
        _moviesCard,
        _fechingMoviesCard,
        moviesInformation,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        &MoviesListModel::updateCardMovie);
}

void MoviesListModel::updateCardMovie(CardMovie *movieCard, const MovieInformation *movieInformation)
{
    movieCard->average = movieInformation->average();
    movieCard->posterUrl = movieInformation->posterUrl();
    movieCard->title = movieInformation->title();
    movieCard->id = movieInformation->id();
    movieCard->isLoading = false;
    movieCard->tpProgram = movieInformation->tpProgram();
}

void MoviesListModel::setTpProgram(TypeProgramEnum newTpProgram)
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

void MoviesListModel::onFetchEnded(QFutureWatcher<SearchMovies *> *future)
{
    if (future->isCanceled()) {
        future->deleteLater();
        _isFetching = false;
        return;
    }

    std::unique_ptr<SearchMovies> searchMovies(future->result());

    if (!searchMovies) {
        future->deleteLater();
        _isFetching = false;
        return;
    }

    updateCardsMovie(_fechingMoviesCard, searchMovies->movies());

    _isFetching = false;

    future->deleteLater();
}

MoviesListModel::CardMovie::CardMovie()
    : title{QStringLiteral("")}
    , posterUrl{QStringLiteral("")}
    , average{0.00}
    , isLoading{true}
    , tpProgram{TypeProgramEnum::UNKNOW}
{}
