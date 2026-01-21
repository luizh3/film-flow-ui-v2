#ifndef NOTIFICATIONCONTROLLER_H
#define NOTIFICATIONCONTROLLER_H

#include <QObject>

#include <core_global.h>

class PaginationRequest;
class NotificationsResult;
class FilmFlowNotificationEndpoint;
class CORE_EXPORT NotificationController : public QObject
{
    Q_OBJECT
public:
    NotificationController();
    ~NotificationController();

    NotificationsResult* findAll(const PaginationRequest* paginationRequest);

    void cancel();

private:
    std::unique_ptr<FilmFlowNotificationEndpoint> _filmFlowNotificationEndpoint;
};

#endif // NOTIFICATIONCONTROLLER_H
