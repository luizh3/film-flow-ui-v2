#ifndef NOTIFICATIONMANAGER_H
#define NOTIFICATIONMANAGER_H

#include <QObject>
#include <websocket/notificationws.h>

class CORE_EXPORT NotificationManager : public QObject
{
    Q_OBJECT
public:
    NotificationManager();

    static NotificationManager *instance();

    void attach(NotificationWs *notificationWs);

signals:
    void newNotification(const int count);

private:
    NotificationWs *_notificationWs;
};

#endif // NOTIFICATIONMANAGER_H
