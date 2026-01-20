#ifndef APPLICATIONCONTROL_H
#define APPLICATIONCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include "control.h"

#include <entities/notification.h>

class ApplicationControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    Q_INVOKABLE void doStart();
signals:
    void success();
    void error(const QString& message);

private:
    void notificationsWsConnect();
};

#endif // APPLICATIONCONTROL_H
