#include "multicontroller.h"

#include <entities/movieinformation.h>
#include <entities/searchmovies.h>

#include <entities/reviewsresult.h>
#include <manager/applicationmanager.h>

#include <network/endpoint/filmflowmultiendpoint.h>
#include <network/request/paginationrequest.h>
#include <network/response/response.h>

MultiController::MultiController()
    : _filmFlowMultiEndpoint{new FilmFlowMultiEndpoint(ApplicationManager::instance().session())}
{}

MultiController::~MultiController() = default;

SearchMovies *MultiController::find(const MultiRequest &request)
{
    std::unique_ptr<Response> response(_filmFlowMultiEndpoint->find(request));

    return SearchMovies::fromJson(response->data());
}

MovieInformation *MultiController::findById(const int id, const MultiDetailsRequest &request)
{
    std::unique_ptr<Response> response(_filmFlowMultiEndpoint->findById(id, request));

    return MovieInformation::fromJson(response->data());
}

ReviewsResult *MultiController::findAllReviewsByIdMovie(const int id,
                                                        const PaginationRequest *request)
{
    std::unique_ptr<Response> response(_filmFlowMultiEndpoint->findAllReviewsByIdMovie(id, request));

    return ReviewsResult::fromJson(response->data());
}

void MultiController::cancel()
{
    _filmFlowMultiEndpoint->cancel();
}
