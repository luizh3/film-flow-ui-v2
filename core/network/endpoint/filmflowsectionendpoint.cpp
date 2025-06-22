#include "filmflowsectionendpoint.h"

#include <QUrlQuery>

#include <network/httpclient.h>
#include <network/request/sectionrequest.h>

namespace {
constexpr const char* SECTION_ENDPOINT = "/section";
}

Response* FilmFlowSectionEndpoint::find( const SectionRequest& request ) {

    QUrl baseUrl( toEndpoint( SECTION_ENDPOINT ) );

    baseUrl.setQuery( request.toQuerys() );

    return HttpClient::get( baseUrl, _headers );
}
