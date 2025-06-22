#include "sectioncontroller.h"

#include <entities/searchmovies.h>

#include <network/response/response.h>
#include <network/endpoint/filmflowsectionendpoint.h>

SearchMovies* SectionController::find(const SectionRequest &request) const
{
    std::unique_ptr<Response> response( FilmFlowSectionEndpoint().find( request ) );

    return SearchMovies::fromJson( response->data() );
}
