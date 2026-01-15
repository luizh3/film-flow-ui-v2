#include "filmflownotificationendpoint.h"

#include <QUrlQuery>

#include <network/httpclient.h>
#include <network/request/paginationrequest.h>

namespace {
constexpr const char *NOTIFICATION_ENDPOINT = "/notification";
}

Response *filmflownotificationendpoint::findAll(const PaginationRequest *request)
{
    QUrl baseUrl(toEndpoint(NOTIFICATION_ENDPOINT));

    baseUrl.setQuery(request->toQuerys());

    return HttpClient().get(baseUrl, _headers);
}
