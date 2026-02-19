#include "searchprogramlistcontrol.h"

#include <core/controller/multicontroller.h>
#include <core/helper/taskrunhelper.h>
#include <core/manager/applicationmanager.h>
#include <core/model/entities/movieinformation.h>
#include <core/model/result/paginationresult.h>
#include <core/model/result/searchmoviesresult.h>
#include <core/network/request/multirequest.h>

SearchProgramListControl::SearchProgramListControl()
    : _multiRequest{new MultiRequest()}
    , _multiController{new MultiController()}
    , _vDsQuery{QStringLiteral("")}
    , _searchProgramListModel{}
{
    // _multiRequest->setDsLanguage(ApplicationManager::instance().languageManager().dsLocaleBCP47());

    QObject::connect(&_searchProgramListModel,
                     &SearchProgramListModel::fetchPrograms,
                     this,
                     &SearchProgramListControl::onFetchPrograms);

    _searchProgramListModel.setIsCanFetch(false);
}

SearchProgramListControl::~SearchProgramListControl()
{
    QObject::disconnect(&_searchProgramListModel,
                        &SearchProgramListModel::fetchPrograms,
                        this,
                        &SearchProgramListControl::onFetchPrograms);

    _multiController->cancel();

    _multiController->deleteLater();

    delete _multiRequest;
}

void SearchProgramListControl::onFetchPrograms()
{
    _multiRequest->setDsQuery(_vDsQuery);
    _multiRequest->setPage(_multiRequest->page() + 1);

    _multiController->find(*_multiRequest).then([&](SearchMoviesResult *result) {
        onFetchEnded(result);
    });
}

void SearchProgramListControl::onFetchEnded(SearchMoviesResult *searchMoviesResult)
{
    if (!searchMoviesResult) {
        return;
    }

    const bool isFirstPage = _multiRequest->page() == 1;

    if (isFirstPage) {
        emit totalProgramsFound(searchMoviesResult->pagination()->totalResult());
    }

    const QList<MovieInformation *> &movies = searchMoviesResult->movies();

    _searchProgramListModel
        .onFetchEnded(movies.count(),
                      [movies](SearchProgramListModel::SearchProgramCard *searchProgramCard,
                               const int index) {
                          SearchProgramListControl::applyToCard(searchProgramCard, movies[index]);
                      });

    delete searchMoviesResult;
}

void SearchProgramListControl::applyToCard(
    SearchProgramListModel::SearchProgramCard *searchProgramCard,
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

QString SearchProgramListControl::vDsQuery() const
{
    return _vDsQuery;
}

void SearchProgramListControl::setVDsQuery(const QString &newVDsQuery)
{
    if (_vDsQuery == newVDsQuery) {
        return;
    }

    _vDsQuery = newVDsQuery;

    _searchProgramListModel.setIsCanFetch(!_vDsQuery.isEmpty());

    _multiController->cancel();

    _multiRequest->setPage(0);

    emit vDsQueryChanged();

    _searchProgramListModel.resetPrograms();
}

SearchProgramListModel *SearchProgramListControl::model()
{
    return &_searchProgramListModel;
}
