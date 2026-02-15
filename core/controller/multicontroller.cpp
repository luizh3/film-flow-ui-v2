#include "multicontroller.h"

#include <model/entities/movieinformation.h>
#include <model/result/searchmoviesresult.h>

#include <manager/applicationmanager.h>
#include <model/result/reviewsresult.h>

#include <network/endpoint/filmflowmultiendpoint.h>
#include <network/request/paginationrequest.h>
#include <network/response/response.h>

#include <helper/taskrunhelper.h>

MultiController::MultiController()
    : _filmFlowMultiEndpoint{new FilmFlowMultiEndpoint(ApplicationManager::instance().session())}
{}

MultiController::~MultiController() = default;

QFuture<SearchMoviesResult *> MultiController::find(const MultiRequest &request)
{
    return TaskRunHelper::promiseAsync<SearchMoviesResult, Response>(
        _filmFlowMultiEndpoint->find(request));
}

QFuture<MovieInformation *> MultiController::findById(const int id,
                                                      const MultiDetailsRequest &request)
{
    return TaskRunHelper::promiseAsync<MovieInformation, Response>(
        _filmFlowMultiEndpoint->findById(id, request));
}

QFuture<ReviewsResult *> MultiController::findAllReviewsByIdMovie(const int id,
                                                                  const PaginationRequest *request)
{
    return TaskRunHelper::promiseAsync<ReviewsResult, Response>(
        _filmFlowMultiEndpoint->findAllReviewsByIdMovie(id, request));
}

void MultiController::cancel()
{
    _filmFlowMultiEndpoint->cancel();
}
