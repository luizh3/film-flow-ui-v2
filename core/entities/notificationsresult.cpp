#include "notificationsresult.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "notification.h"
#include "notificationreviewlike.h"
#include "pagination.h"

NotificationsResult::~NotificationsResult()
{
    qDeleteAll(_notifications);
    delete _pagination;
}

NotificationsResult::NotificationsResult()
    : _pagination{nullptr}
    , _notifications{}
{}

NotificationsResult::NotificationsResult(Pagination *pagination, QList<Notification *> notifications)
    : _pagination{pagination}
    , _notifications{notifications}
{}

Pagination *NotificationsResult::pagination() const
{
    return _pagination;
}

void NotificationsResult::setPagination(Pagination *newPagination)
{
    _pagination = newPagination;
}

QList<Notification *> NotificationsResult::notifications() const
{
    return _notifications;
}

void NotificationsResult::setNotifications(const QList<Notification *> &newNotifications)
{
    _notifications = newNotifications;
}

NotificationsResult *NotificationsResult::fromJson(const QJsonDocument &jsonDocument)
{
    QList<Notification *> notifications = {};

    const QJsonArray notificationsArray = jsonDocument["notifications"].toArray();

    for (const QJsonValue &&notificationValue : notificationsArray) {
        switch (TypeNotificaton::fromString(notificationValue["type"].toString())) {
        case TypeNotificationEnum::REVIEW_LIKE: {
            Notification *notificationReviewLike = new NotificationReviewLike();
            notificationReviewLike->fromJson(notificationValue["data"].toObject());
            notifications.append(notificationReviewLike);
            break;
        }
        default: {
            break;
        }
        }
    }

    return new NotificationsResult(Pagination::fromJson(jsonDocument.object()), notifications);
}
