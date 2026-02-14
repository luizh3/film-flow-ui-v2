#include "notificationsresult.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "paginationresult.h"
#include <model/entities/notification.h>
#include <model/entities/notificationreviewlike.h>

NotificationsResult::~NotificationsResult()
{
    qDeleteAll(_notifications);
    delete _pagination;
}

NotificationsResult::NotificationsResult()
    : _pagination{nullptr}
    , _notifications{}
{}

NotificationsResult::NotificationsResult(PaginationResult *pagination,
                                         QList<Notification *> notifications)
    : _pagination{pagination}
    , _notifications{notifications}
{}

PaginationResult *NotificationsResult::pagination() const
{
    return _pagination;
}

void NotificationsResult::setPagination(PaginationResult *newPagination)
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

    return new NotificationsResult(PaginationResult::fromJson(jsonDocument.object()), notifications);
}
