#include "sectioncontroller.h"

#include <entities/searchmovies.h>

#include <manager/applicationmanager.h>

#include <network/response/response.h>

SectionController::SectionController()
    : _filmFlowSectionEndpoint{ApplicationManager::instance().session()}
{}

SearchMovies *SectionController::find(const SectionRequest &request)
{
    std::unique_ptr<Response> response(_filmFlowSectionEndpoint.find(request));

    return SearchMovies::fromJson( response->data() );
}
