#include "reviewcontroller.h"

#include <entities/review.h>
#include <entities/reviewsresult.h>

#include <network/endpoint/filmflowreviewendpoint.h>
#include <network/response/response.h>

void ReviewController::create(const Review *review)
{
    std::unique_ptr<Response> response(FilmFlowReviewEndpoint().create(review));

    if (!response || !response->isStatusValid()) {
        emit error(tr("Fail on create review!"));
        return;
    }

    emit success(Review::fromJson(response->data()));
}

void ReviewController::update(const Review *review)
{
    std::unique_ptr<Response> response(FilmFlowReviewEndpoint().update(review));

    if (!response || !response->isStatusValid()) {
        emit error(tr("Fail on update review!"));
        return;
    }

    emit success(Review::fromJson(response->data()));
}

ReviewsResult *ReviewController::findAll(const PaginationRequest *paginationRequest)
{
    std::unique_ptr<Response> response(FilmFlowReviewEndpoint().findAll(paginationRequest));

    return ReviewsResult::fromJson(response->data());
}
