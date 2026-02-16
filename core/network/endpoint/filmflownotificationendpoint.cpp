#include "filmflownotificationendpoint.h"

#include <QUrlQuery>

#include <network/httpclient.h>
#include <network/request/paginationrequest.h>

namespace {
constexpr const char *NOTIFICATION_ENDPOINT = "/notification";
}

FilmFlowNotificationEndpoint::FilmFlowNotificationEndpoint(const Session *session)
    : FilmFlowEndpoint(session)
{}

QFuture<Response *> FilmFlowNotificationEndpoint::findAll(const PaginationRequest *request)
{
    QUrl baseUrl(toEndpoint(NOTIFICATION_ENDPOINT));

    baseUrl.setQuery(request->toQuerys());

    return _httpClient->getAsync(baseUrl, _headers, QNetworkRequest::CacheLoadControl::PreferCache);
}
