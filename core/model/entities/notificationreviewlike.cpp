#include "notificationreviewlike.h"

#include <QJsonDocument>
#include <QJsonObject>

NotificationReviewLike::NotificationReviewLike()
    : _reviewId{QStringLiteral("")}
    , _actorId{QStringLiteral("")}
    , _actorName(QStringLiteral(""))
    , _avatarUrl{QStringLiteral("")}
    , _programId{QStringLiteral("")}
    , _programTitle{QStringLiteral("")}

{}

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

QString NotificationReviewLike::actorId() const
{
    return _actorId;
}

void NotificationReviewLike::setActorId(const QString &newActorId)
{
    _actorId = newActorId;
}

QString NotificationReviewLike::actorName() const
{
    return _actorName;
}

void NotificationReviewLike::setActorName(const QString &newActorName)
{
    _actorName = newActorName;
}

QString NotificationReviewLike::avatarUrl() const
{
    return _avatarUrl;
}

void NotificationReviewLike::setAvatarUrl(const QString &newAvatarUrl)
{
    _avatarUrl = newAvatarUrl;
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

void NotificationReviewLike::fromJson(const QJsonObject &jsonObject)
{
    const QJsonObject reviewObject = jsonObject["review"].toObject();
    const QJsonObject actorObject = jsonObject["actor"].toObject();
    const QJsonObject programObject = jsonObject["program"].toObject();

    _reviewId = reviewObject["id"].toString();
    _actorId = actorObject["id"].toString();
    _actorName = actorObject["name"].toString();
    _avatarUrl = actorObject["avatarUrl"].toString();
    _programId = programObject["id"].toString();
    _programTitle = programObject["title"].toString();
}
