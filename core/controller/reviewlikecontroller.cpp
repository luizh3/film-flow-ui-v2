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
    _filmFlowReviewEndpoint->like(reviewId).then([&](Response *response) {
        if (!response || !response->isStatusValid()) {
            delete response;
            emit errorLiked(tr("Fail on like review!"));
            return;
        }

        emit successLiked();
        delete response;
    });
}

void ReviewLikeController::unlike(const QString &reviewId)
{
    _filmFlowReviewEndpoint->unlike(reviewId).then([&](Response *response) {
        if (!response || !response->isStatusValid()) {
            delete response;
            emit errorUnliked(tr("Fail on unlike review!"));
            return;
        }

        emit successUnliked();
        delete response;
    });
}

void ReviewLikeController::cancel()
{
    _filmFlowReviewEndpoint->cancel();
}
