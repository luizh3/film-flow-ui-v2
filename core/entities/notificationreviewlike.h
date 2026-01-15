#ifndef NOTIFICATIONREVIEWLIKE_H
#define NOTIFICATIONREVIEWLIKE_H

#include "notification.h"

#include <core_global.h>

class CORE_EXPORT NotificationReviewLike : public Notification
{
public:
    NotificationReviewLike();

    virtual TypeNotificationEnum type();

    QString reviewId() const;
    void setReviewId(const QString &newReviewId);

    QString actorId() const;
    void setActorId(const QString &newActorId);

    QString actorName() const;
    void setActorName(const QString &newActorName);

    QString avatarUrl() const;
    void setAvatarUrl(const QString &newAvatarUrl);

    QString programId() const;
    void setProgramId(const QString &newProgramId);

    QString programTitle() const;
    void setProgramTitle(const QString &newProgramTitle);

    virtual void fromJson(const QJsonObject &jsonDocument);

private:
    QString _reviewId;
    QString _actorId;
    QString _actorName;
    QString _avatarUrl;
    QString _programId;
    QString _programTitle;
};

#endif // NOTIFICATIONREVIEWLIKE_H
