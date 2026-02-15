#ifndef NOTIFICATIONCONTROLLER_H
#define NOTIFICATIONCONTROLLER_H

#include <QObject>

#include <core_global.h>

#include <QFuture>

class PaginationRequest;
class NotificationsResult;
class FilmFlowNotificationEndpoint;
class CORE_EXPORT NotificationController : public QObject
{
    Q_OBJECT
public:
    NotificationController();
    ~NotificationController();

    QFuture<NotificationsResult*> findAll(const PaginationRequest* paginationRequest);

    void cancel();

private:
    std::unique_ptr<FilmFlowNotificationEndpoint> _filmFlowNotificationEndpoint;
};

#endif // NOTIFICATIONCONTROLLER_H
