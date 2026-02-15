#include "reviewcontroller.h"

#include <model/entities/review.h>
#include <model/result/reviewsresult.h>

#include <manager/applicationmanager.h>
#include <network/endpoint/filmflowreviewendpoint.h>
#include <network/response/response.h>

#include <helper/taskrunhelper.h>

ReviewController::~ReviewController() = default;

ReviewController::ReviewController()
    : _filmFlowReviewEndpoint{new FilmFlowReviewEndpoint(ApplicationManager::instance().session())}
{}

void ReviewController::create(const Review *review)
{
    std::unique_ptr<Response> response(_filmFlowReviewEndpoint->create(review));

    if (!response || !response->isStatusValid()) {
        emit error(tr("Fail on create review!"));
        return;
    }

    emit success(Review::fromJson(response->data()));
}

void ReviewController::update(const Review *review)
{
    std::unique_ptr<Response> response(_filmFlowReviewEndpoint->update(review));

    if (!response || !response->isStatusValid()) {
        emit error(tr("Fail on update review!"));
        return;
    }

    emit success(Review::fromJson(response->data()));
}

QFuture<ReviewsResult *> ReviewController::findAll(const PaginationRequest *paginationRequest)
{
    return TaskRunHelper::promiseAsync<ReviewsResult, Response>(
        _filmFlowReviewEndpoint->findAll(paginationRequest));
}

void ReviewController::cancel() const
{
    _filmFlowReviewEndpoint->cancel();
}
