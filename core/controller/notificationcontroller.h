#ifndef NOTIFICATIONCONTROLLER_H
#define NOTIFICATIONCONTROLLER_H

#include <QObject>

#include <core_global.h>

#include <network/endpoint/filmflownotificationendpoint.h>

class PaginationRequest;
class NotificationsResult;
class CORE_EXPORT NotificationController : public QObject
{
    Q_OBJECT
public:
    NotificationController();

    NotificationsResult* findAll(const PaginationRequest* paginationRequest);

private:
    FilmFlowNotificationEndpoint _filmFlowNotificationEndpoint;
};

#endif // NOTIFICATIONCONTROLLER_H
