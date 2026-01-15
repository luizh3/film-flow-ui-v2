#ifndef NOTIFICATIONSRESULT_H
#define NOTIFICATIONSRESULT_H

#include <QList>

#include "core_global.h"

class Pagination;
class Notification;
class QJsonDocument;
class CORE_EXPORT NotificationsResult
{
public:
    ~NotificationsResult();
    NotificationsResult();
    NotificationsResult(Pagination *pagination, QList<Notification *> notifications);

    Pagination *pagination() const;
    void setPagination(Pagination *newPagination);

    QList<Notification *> notifications() const;
    void setNotifications(const QList<Notification *> &newNotifications);

    static NotificationsResult *fromJson(const QJsonDocument &jsonDocument);

private:
    Pagination *_pagination;
    QList<Notification *> _notifications;
};

#endif // NOTIFICATIONSRESULT_H
