#include "notificationws.h"

#include <QJsonDocument>
#include <QJsonObject>

#include "entities/notification.h"

NotificationWs::NotificationWs(const QUrl &dsUrl, const QString &dsToken)
{
    connect(&_socket, &QWebSocket::connected, this, &NotificationWs::onConnected);
    connect(&_socket, &QWebSocket::textMessageReceived, this, &NotificationWs::onMessageReceived);
    connect(&_socket, &QWebSocket::disconnected, this, &NotificationWs::onDisconnected);

    QNetworkRequest request(dsUrl);
    request.setRawHeader("Authorization", dsToken.toUtf8());

    _socket.open(request);
}

void NotificationWs::onMessageReceived(const QString &message)
{
    QJsonDocument document = QJsonDocument::fromJson(message.toUtf8());

    qInfo() << "NotificationWs::onMessageReceived [PAYLOAD]" << document;

    const int count = 1;

    emit newNotification(count);
}

void NotificationWs::onConnected()
{
    qInfo() << "NotificationWs::onConnected connected";
}

void NotificationWs::onDisconnected()
{
    qInfo() << "NotificationWs::onDisconnected disconnect";
}
