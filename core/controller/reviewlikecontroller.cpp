#include "reviewlikecontroller.h"

#include <network/endpoint/filmflowreviewendpoint.h>
#include <network/response/response.h>

#include <manager/applicationmanager.h>

ReviewLikeController::~ReviewLikeController() = default;

ReviewLikeController::ReviewLikeController()
    : _filmFlowReviewEndpoint{new FilmFlowReviewEndpoint(ApplicationManager::instance().session())}
{}

void ReviewLikeController::like(const QString &reviewId)
{
    std::unique_ptr<Response> response(_filmFlowReviewEndpoint->like(reviewId));

    if (!response || !response->isStatusValid()) {
        emit errorLiked(tr("Fail on like review!"));
        return;
    }

    emit successLiked();
}

void ReviewLikeController::unlike(const QString &reviewId)
{
    std::unique_ptr<Response> response(_filmFlowReviewEndpoint->unlike(reviewId));

    if (!response || !response->isStatusValid()) {
        emit errorUnliked(tr("Fail on unlike review!"));
        return;
    }

    emit successUnliked();
}

void ReviewLikeController::cancel()
{
    _filmFlowReviewEndpoint->cancel();
}
