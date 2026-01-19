#include "reviewcontroller.h"

#include <entities/review.h>
#include <entities/reviewsresult.h>

#include <manager/applicationmanager.h>
#include <network/response/response.h>

ReviewController::ReviewController()
    : _filmFlowReviewEndpoint{ApplicationManager::instance().session()}
{}

void ReviewController::create(const Review *review)
{
    std::unique_ptr<Response> response(_filmFlowReviewEndpoint.create(review));

    if (!response || !response->isStatusValid()) {
        emit error(tr("Fail on create review!"));
        return;
    }

    emit success(Review::fromJson(response->data()));
}

void ReviewController::update(const Review *review)
{
    std::unique_ptr<Response> response(_filmFlowReviewEndpoint.update(review));

    if (!response || !response->isStatusValid()) {
        emit error(tr("Fail on update review!"));
        return;
    }

    emit success(Review::fromJson(response->data()));
}

ReviewsResult *ReviewController::findAll(const PaginationRequest *paginationRequest)
{
    std::unique_ptr<Response> response(_filmFlowReviewEndpoint.findAll(paginationRequest));

    return ReviewsResult::fromJson(response->data());
}
