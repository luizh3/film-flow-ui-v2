#include "filmflowconfigendpoint.h"

#include <network/httpclient.h>

namespace {
constexpr const char* CONFIG_ENDPOINT = "/config";
}

FilmFlowConfigEndpoint::FilmFlowConfigEndpoint(const Session* session)
    : FilmFlowEndpoint(session)
{}

Response* FilmFlowConfigEndpoint::configs() const
{
    return _httpClient->get(toEndpoint(CONFIG_ENDPOINT), _headers);
}
