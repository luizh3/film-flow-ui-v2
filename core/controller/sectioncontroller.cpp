#include "sectioncontroller.h"

#include <entities/searchmovies.h>

#include <manager/applicationmanager.h>

#include <network/endpoint/filmflowsectionendpoint.h>
#include <network/response/response.h>

SectionController::SectionController()
    : _filmFlowSectionEndpoint{new FilmFlowSectionEndpoint(ApplicationManager::instance().session())}
{}

SectionController::~SectionController() = default;

SearchMovies *SectionController::find(const SectionRequest &request)
{
    std::unique_ptr<Response> response(_filmFlowSectionEndpoint->find(request));

    if (!response) {
        return nullptr;
    }

    return SearchMovies::fromJson( response->data() );
}

void SectionController::cancel()
{
    _filmFlowSectionEndpoint->cancel();
}
