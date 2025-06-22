#include "filmflowconfigendpoint.h"

#include <network/httpclient.h>

namespace {
constexpr const char* CONFIG_ENDPOINT = "/config";
}

Response* FilmFlowConfigEndpoint::configs() const {
    return HttpClient::get( toEndpoint(CONFIG_ENDPOINT), _headers );
}
