#include "reviewprogrammodalcontrol.h"

#include <QDebug>

#include <core/controller/reviewcontroller.h>

#include "mapper/reviewmapper.h"

void ReviewProgramModalControl::doConfirm(const ReviewModel *review) const
{
    const bool isNewReview = review->reviewId().isEmpty();

    if (isNewReview)
    {
        doCreate(review);
        return;
    }

    doUpdate(review);
}

void ReviewProgramModalControl::doCreate(const ReviewModel *review) const
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

    std::unique_ptr<Review> reviewEntity(ReviewMapper::toEntity(review));

    controller.create(reviewEntity.get());

    qInfo() << "ReviewProgramModalControl::doCreate";
}

void ReviewProgramModalControl::doUpdate(const ReviewModel *review) const
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

    std::unique_ptr<Review> reviewEntity(ReviewMapper::toEntity(review));

    controller.update(reviewEntity.get());

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

    emit success(ReviewMapper::toModel(review));

    qInfo() << "ReviewProgramModalControl::onSuccess";
}
