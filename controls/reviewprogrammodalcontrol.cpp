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

    QObject::connect(&controller,
                     &ReviewController::error,
                     this,
                     &ReviewProgramModalControl::onError);
    QObject::connect(&controller,
                     &ReviewController::success,
                     this,
                     &ReviewProgramModalControl::onSuccess);

    controller.create(review);

    qInfo() << "ReviewProgramModalControl::doCreate";
}

void ReviewProgramModalControl::doUpdate(const Review *review) const
{
    qInfo() << "ReviewProgramModalControl::Update";

    ReviewController controller;

    QObject::connect(&controller,
                     &ReviewController::error,
                     this,
                     &ReviewProgramModalControl::onError);
    QObject::connect(&controller,
                     &ReviewController::success,
                     this,
                     &ReviewProgramModalControl::onSuccess);

    controller.update(review);

    qInfo() << "ReviewProgramModalControl::Update";
}

void ReviewProgramModalControl::onError(const QString &message)
{
    qInfo() << "ReviewProgramModalControl::onError [MESSAGE]" << message;

    toastError(message);

    emit error(message);

    qInfo() << "ReviewProgramModalControl::onError";
}

void ReviewProgramModalControl::onSuccess(Review *review)
{
    qInfo() << "ReviewProgramModalControl::onSuccess";

    toastSuccess(tr("Success on created review!"));

    emit success(review);

    qInfo() << "ReviewProgramModalControl::onSuccess";
}
