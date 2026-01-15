#include "searchprogramlistmodel.h"

#include <core/controller/multicontroller.h>
#include <core/entities/movieinformation.h>
#include <core/entities/searchmovies.h>
#include <core/helper/taskrunhelper.h>
#include <core/manager/applicationmanager.h>
#include <core/network/request/multirequest.h>

#include "helper/cardsfetchhelper.h"

namespace {
constexpr int NR_MOVIES_BY_PAGE = 20;
}

SearchProgramListModel::SearchProgramListModel()
    : _multiRequest{new MultiRequest()}
    , _multiController{new MultiController()}
    , _isFetching{false}
    , _fechingSearchProgramCards{}
    , _programCards{}
{
    _multiRequest->setDsLanguage(ApplicationManager::instance().languageManager().dsLocaleBCP47());
}

SearchProgramListModel::~SearchProgramListModel()
{
    delete _multiRequest;
    delete _multiController;

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
    case Title:
        return _programCards.at(row)->title;
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
    if (parent.isValid() || _isFetching || _vDsQuery.isEmpty()) {
        return;
    }

    _isFetching = true;

    _multiRequest->setDsQuery(_vDsQuery);
    _multiRequest->setPage(_multiRequest->page() + 1);

    CardFetchHelper::appendFetchingCards<SearchProgramCard>(
        _programCards,
        _fechingSearchProgramCards,
        NR_MOVIES_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new SearchProgramCard(); });

    _future = TaskRunHelper::async<SearchMovies *>(
        [&]() { return _multiController->find(*_multiRequest); });

    QObject::connect(_future, &QFutureWatcher<SearchMovies *>::finished, this, [this]() {
        onFetchEnded(_future);
    });
}

bool SearchProgramListModel::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return false;
    }

    return !_isFetching;
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

void SearchProgramListModel::updateCardsMovie(const QList<SearchProgramCard *> &searchProgramCards,
                                              const QList<MovieInformation *> &moviesInformation)
{
    CardFetchHelper::updateCards<SearchProgramCard, MovieInformation>(
        _programCards,
        _fechingSearchProgramCards,
        moviesInformation,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        &SearchProgramListModel::updateCardMovie);
}

void SearchProgramListModel::updateCardMovie(SearchProgramCard *searchProgramCard,
                                             const MovieInformation *movieInformation)
{
    searchProgramCard->average = movieInformation->average();
    searchProgramCard->posterUrl = movieInformation->posterUrl();
    searchProgramCard->title = movieInformation->title();
    searchProgramCard->id = movieInformation->id();
    searchProgramCard->isLoading = false;
    searchProgramCard->tpProgram = movieInformation->tpProgram();
    searchProgramCard->overview = movieInformation->overview();
}

QString SearchProgramListModel::vDsQuery() const
{
    return _vDsQuery;
}

void SearchProgramListModel::setVDsQuery(const QString &newVDsQuery)
{
    if (_vDsQuery == newVDsQuery) {
        return;
    }

    _vDsQuery = newVDsQuery;

    _multiController->cancel();

    if (_future) {
        _future->cancel();
    } else {
        beginResetModel();
        qDeleteAll(_programCards);
        _programCards.clear();
        _fechingSearchProgramCards.clear();
        _multiRequest->setPage(0);
        endResetModel();
    }

    emit vDsQueryChanged();
}

void SearchProgramListModel::onFetchEnded(QFutureWatcher<SearchMovies *> *future)
{
    if (_future->isFinished() && !_future->isCanceled()) {
        std::unique_ptr<SearchMovies> searchMovies(_future->result());

        updateCardsMovie(_fechingSearchProgramCards, searchMovies->movies());
    }

    if (_future->isCanceled()) {
        beginResetModel();

        qDeleteAll(_programCards);
        _programCards.clear();
        _fechingSearchProgramCards.clear();

        _future->deleteLater();
        _multiRequest->setPage(0);

        _future = nullptr;

        _isFetching = false;

        endResetModel();

        return;
    }

    _isFetching = false;

    _future->deleteLater();

    _future = nullptr;
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
