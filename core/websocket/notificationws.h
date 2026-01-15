#ifndef NOTIFICATIONWS_H
#define NOTIFICATIONWS_H

#include <QObject>
#include <QWebSocket>

#include <core_global.h>

#include <entities/notification.h>

class CORE_EXPORT NotificationWs : public QObject
{
    Q_OBJECT
public:
    explicit NotificationWs(const QUrl &dsUrl, const QString &dsToken);

signals:
    void newNotification(const int count);
private slots:
    void onMessageReceived(const QString &message);
    void onConnected();
    void onDisconnected();

private:
    QWebSocket _socket;
};

#endif // NOTIFICATIONWS_H
