#include "movieslistmodel.h"

#include "helper/cardsfetchhelper.h"

namespace {
constexpr int NR_MOVIES_BY_PAGE = 20;
}

MoviesListModel::~MoviesListModel()
{
    qDeleteAll(_moviesCard);
}

MoviesListModel::MoviesListModel()
    : _isFetching{false}
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

    CardFetchHelper::appendFetchingCards<CardMovie>(
        _moviesCard,
        _fechingMoviesCard,
        NR_MOVIES_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new CardMovie(); });

    emit fetchMovies();
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

void MoviesListModel::updateCardsMovie(
    const int nrItensFetch,
    std::function<void(MoviesListModel::CardMovie *, const int index)> bindCardCallback)
{
    CardFetchHelper::updateCards<CardMovie>(
        _moviesCard,
        _fechingMoviesCard,
        nrItensFetch,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        bindCardCallback);
}

void MoviesListModel::onFetchEnded(
    const int nrItensFetch,
    std::function<void(MoviesListModel::CardMovie *, const int index)> bindCardCallback)
{
    updateCardsMovie(nrItensFetch, bindCardCallback);

    _isFetching = false;
}

MoviesListModel::CardMovie::CardMovie()
    : title{QStringLiteral("")}
    , posterUrl{QStringLiteral("")}
    , average{0.00}
    , isLoading{true}
    , tpProgram{TypeProgramEnum::UNKNOW}
{}
