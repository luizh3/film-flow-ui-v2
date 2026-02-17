#ifndef NOTIFICATIONREVIEWLIKE_H
#define NOTIFICATIONREVIEWLIKE_H

#include "notification.h"

#include <core_global.h>

class User;
class CORE_EXPORT NotificationReviewLike : public Notification
{
public:
    NotificationReviewLike();
    ~NotificationReviewLike();

    virtual TypeNotificationEnum type();

    QString reviewId() const;
    void setReviewId(const QString &newReviewId);

    QString programId() const;
    void setProgramId(const QString &newProgramId);

    QString programTitle() const;
    void setProgramTitle(const QString &newProgramTitle);

    User *actor() const;
    void setActor(std::unique_ptr<User> newActor);

    virtual void fromJson(const QJsonObject &jsonDocument);

private:
    std::unique_ptr<User> _actor;
    QString _reviewId;
    QString _programId;
    QString _programTitle;
};

#endif // NOTIFICATIONREVIEWLIKE_H
