#include "notificationreviewlike.h"

#include <QJsonDocument>
#include <QJsonObject>

#include "user.h"

NotificationReviewLike::NotificationReviewLike()
    : _actor{nullptr}
    , _reviewId{QStringLiteral("")}
    , _programId{QStringLiteral("")}
    , _programTitle{QStringLiteral("")}
{}

NotificationReviewLike::~NotificationReviewLike() = default;

TypeNotificationEnum NotificationReviewLike::type()
{
    return TypeNotificationEnum::REVIEW_LIKE;
}

QString NotificationReviewLike::reviewId() const
{
    return _reviewId;
}

void NotificationReviewLike::setReviewId(const QString &newReviewId)
{
    _reviewId = newReviewId;
}

QString NotificationReviewLike::programId() const
{
    return _programId;
}

void NotificationReviewLike::setProgramId(const QString &newProgramId)
{
    _programId = newProgramId;
}

QString NotificationReviewLike::programTitle() const
{
    return _programTitle;
}

void NotificationReviewLike::setProgramTitle(const QString &newProgramTitle)
{
    _programTitle = newProgramTitle;
}

User *NotificationReviewLike::actor() const
{
    return _actor.get();
}

void NotificationReviewLike::setActor(std::unique_ptr<User> newActor)
{
    _actor = std::move(newActor);
}

void NotificationReviewLike::fromJson(const QJsonObject &jsonObject)
{
    const QJsonObject reviewObject = jsonObject["review"].toObject();
    const QJsonObject actorObject = jsonObject["actor"].toObject();
    const QJsonObject programObject = jsonObject["program"].toObject();

    _reviewId = reviewObject["id"].toString();
    _programId = programObject["id"].toString();
    _programTitle = programObject["title"].toString();

    _actor.reset(User::fromJson(actorObject));
}
