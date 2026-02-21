#ifndef NOTIFICATIONSCONTROL_H
#define NOTIFICATIONSCONTROL_H

#include <QObject>
#include <QQmlEngine>

class NotificationsControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit NotificationsControl();

signals:
    void newNotification(const int count);
};

#endif // NOTIFICATIONSCONTROL_H
