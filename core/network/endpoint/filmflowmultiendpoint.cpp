#include "filmflowmultiendpoint.h"

#include <QUrlQuery>

#include <network/request/multidetailsrequest.h>
#include <network/request/multirequest.h>
#include <network/request/paginationrequest.h>

namespace {
constexpr const char *MULTI_ENDPOINT = "/multi";
constexpr const char *MULTI_FIND_BY_ID = "/multi/%0";
constexpr const char *MULTI_FIND_REVIEWS_BY_ID = "/multi/%0/reviews";
}

FilmFlowMultiEndpoint::FilmFlowMultiEndpoint(const Session *session)
    : FilmFlowEndpoint(session)
{}

Response *FilmFlowMultiEndpoint::find(const MultiRequest &request)
{
    QUrl baseUrl(toEndpoint(MULTI_ENDPOINT));

    baseUrl.setQuery(request.toQuerys());

    return _httpClient.get(baseUrl, _headers);
}

Response *FilmFlowMultiEndpoint::findById(const int id, const MultiDetailsRequest &request)
{
    QUrl baseUrl(toEndpoint(QString(MULTI_FIND_BY_ID).arg(id)));

    baseUrl.setQuery(request.toQuerys());

    return _httpClient.get(baseUrl, _headers);
}

Response *FilmFlowMultiEndpoint::findAllReviewsByIdMovie(const int id,
                                                         const PaginationRequest *request)
{
    QUrl baseUrl(toEndpoint(QString(MULTI_FIND_REVIEWS_BY_ID).arg(id)));

    baseUrl.setQuery(request->toQuerys());

    return _httpClient.get(baseUrl, _headers);
}

void FilmFlowMultiEndpoint::cancel()
{
    _httpClient.cancel();
}
