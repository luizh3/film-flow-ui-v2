#include "searchprogramlistmodel.h"

#include "helper/cardsfetchhelper.h"

namespace {
constexpr int NR_MOVIES_BY_PAGE = 20;
}

SearchProgramListModel::SearchProgramListModel()
    : _isFetching{false}
    , _isCanFetch{false}
    , _fechingSearchProgramCards{}
    , _programCards{}
{}

SearchProgramListModel::~SearchProgramListModel()
{
    qDeleteAll(_programCards);
}

int SearchProgramListModel::rowCount(const QModelIndex &parent) const
{
    return _programCards.count();
}

QVariant SearchProgramListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || _programCards.isEmpty()) {
        return QVariant();
    }

    const int row = index.row();

    switch (role) {
    case Title: {
        return _programCards.at(row)->title;
    }
    case PosterUrl: {
        return _programCards.at(row)->posterUrl;
    }
    case Average: {
        return _programCards.at(row)->average;
    }
    case IsLoading: {
        return _programCards.at(row)->isLoading;
    }
    case Genres: {
        return _programCards.at(row)->genres;
    }
    case Id: {
        return _programCards.at(row)->id;
    }
    case TpProgram: {
        return QVariant::fromValue(_programCards.at(row)->tpProgram);
    }
    case Overview: {
        return _programCards.at(row)->overview;
    }
    default:
        return QVariant();
    }
}

void SearchProgramListModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid() || _isFetching || !_isCanFetch) {
        return;
    }

    _isFetching = true;

    CardFetchHelper::appendFetchingCards<SearchProgramCard>(
        _programCards,
        _fechingSearchProgramCards,
        NR_MOVIES_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new SearchProgramCard(); });

    emit fetchPrograms();
}

bool SearchProgramListModel::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return false;
    }

    return !_isFetching && _isCanFetch;
}

QHash<int, QByteArray> SearchProgramListModel::roleNames() const
{
    static QHash<int, QByteArray> mapping{{Title, "title"},
                                          {PosterUrl, "posterUrl"},
                                          {Average, "average"},
                                          {Genres, "genres"},
                                          {Id, "id"},
                                          {IsLoading, "isLoading"},
                                          {Overview, "overview"},
                                          {TpProgram, "tpProgram"}};

    return mapping;
}

void SearchProgramListModel::resetPrograms()
{
    beginResetModel();

    qDeleteAll(_programCards);

    _programCards.clear();

    _fechingSearchProgramCards.clear();

    endResetModel();
}

void SearchProgramListModel::updateCardsMovie(
    const int nrItensFetch,
    std::function<void(SearchProgramListModel::SearchProgramCard *, const int index)>
        bindCardCallback)
{
    CardFetchHelper::updateCards<SearchProgramCard>(
        _programCards,
        _fechingSearchProgramCards,
        nrItensFetch,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        bindCardCallback);
}

void SearchProgramListModel::onFetchEnded(
    const int nrItensFetch,
    std::function<void(SearchProgramListModel::SearchProgramCard *, const int index)>
        bindCardCallback)
{
    updateCardsMovie(nrItensFetch, bindCardCallback);

    _isFetching = false;
}

void SearchProgramListModel::setIsCanFetch(const bool isCanFetch)
{
    _isCanFetch = isCanFetch;
}

SearchProgramListModel::SearchProgramCard::SearchProgramCard()
    : title{QStringLiteral("")}
    , posterUrl(QStringLiteral(""))
    , genres(QStringLiteral(""))
    , overview(QStringLiteral(""))
    , average{0.00}
    , isLoading{true}
    , tpProgram(TypeProgramEnum::UNKNOW)
{}
