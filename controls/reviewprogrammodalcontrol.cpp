#include "reviewprogrammodalcontrol.h"

#include <QDebug>

#include <core/controller/reviewcontroller.h>

void ReviewProgramModalControl::doConfirm(const Review *review) const
{
    const bool isNewReview = review->reviewId().isEmpty();

    if (isNewReview) {
        doCreate(review);
        return;
    }

    doUpdate(review);
}

void ReviewProgramModalControl::doCreate(const Review *review) const
{
    qInfo() << "ReviewProgramModalControl::doCreate";

    ReviewController controller;

    QObject::connect(&controller, &ReviewController::error, this, &ReviewProgramModalControl::error);
    QObject::connect(&controller,
                     &ReviewController::success,
                     this,
                     &ReviewProgramModalControl::success);

    controller.create(review);

    qInfo() << "ReviewProgramModalControl::doCreate";
}

void ReviewProgramModalControl::doUpdate(const Review *review) const
{
    qInfo() << "ReviewProgramModalControl::Update";

    ReviewController controller;

    QObject::connect(&controller, &ReviewController::error, this, &ReviewProgramModalControl::error);
    QObject::connect(&controller,
                     &ReviewController::success,
                     this,
                     &ReviewProgramModalControl::success);

    controller.update(review);

    qInfo() << "ReviewProgramModalControl::Update";
}
