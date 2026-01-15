#ifndef NOTIFICATIONCONTROLLER_H
#define NOTIFICATIONCONTROLLER_H

#include <QObject>

#include <core_global.h>

class PaginationRequest;
class NotificationsResult;
class CORE_EXPORT NotificationController : public QObject
{
    Q_OBJECT
public:
    NotificationsResult* findAll(const PaginationRequest* paginationRequest);
};

#endif // NOTIFICATIONCONTROLLER_H
