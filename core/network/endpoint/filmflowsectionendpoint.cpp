#include "filmflowsectionendpoint.h"

#include <QUrlQuery>

#include <network/httpclient.h>
#include <network/request/sectionrequest.h>

namespace {
constexpr const char* SECTION_ENDPOINT = "/section";
}

FilmFlowSectionEndpoint::FilmFlowSectionEndpoint(const Session* session)
    : FilmFlowEndpoint(session)
{}

Response* FilmFlowSectionEndpoint::find(const SectionRequest& request)
{
    QUrl baseUrl(toEndpoint(SECTION_ENDPOINT));

    baseUrl.setQuery( request.toQuerys() );

    return _httpClient->get(baseUrl, _headers);
}
