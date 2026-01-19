#include "programreviewcontrol.h"

#include <core/helper/taskrunhelper.h>
#include <core/network/endpoint/filmflowreviewendpoint.h>

ProgramReviewControl::ProgramReviewControl()
{
    QObject::connect(&_reviewLikeController,
                     &ReviewLikeController::errorLiked,
                     this,
                     &ProgramReviewControl::rollbackLike);

    QObject::connect(&_reviewLikeController,
                     &ReviewLikeController::errorUnliked,
                     this,
                     &ProgramReviewControl::rollbackUnlike);
}

void ProgramReviewControl::like(const QString &reviewId)
{
    _reviewLikeController.cancel();

    TaskRunHelper::runSync([&]() { _reviewLikeController.like(reviewId); });
}

void ProgramReviewControl::unlike(const QString &reviewId)
{
    _reviewLikeController.cancel();

    TaskRunHelper::runSync([&]() { _reviewLikeController.unlike(reviewId); });
}
