#ifndef NOTIFICATIONSRESULT_H
#define NOTIFICATIONSRESULT_H

#include <QList>

#include "core_global.h"

class PaginationResult;
class Notification;
class QJsonDocument;
class CORE_EXPORT NotificationsResult
{
public:
    ~NotificationsResult();
    NotificationsResult();
    NotificationsResult(PaginationResult *pagination, QList<Notification *> notifications);

    PaginationResult *pagination() const;
    void setPagination(PaginationResult *newPagination);

    QList<Notification *> notifications() const;
    void setNotifications(const QList<Notification *> &newNotifications);

    static NotificationsResult *fromJson(const QJsonDocument &jsonDocument);

private:
    PaginationResult *_pagination;
    QList<Notification *> _notifications;
};

#endif // NOTIFICATIONSRESULT_H
