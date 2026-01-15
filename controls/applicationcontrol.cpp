#include "applicationcontrol.h"

#include <core/controller/applicationcontroller.h>

#include <manager/notificationmanager.h>

#include <entities/notificationreviewlike.h>

void ApplicationControl::doStart()
{
    notificationsWsConnect();
}

void ApplicationControl::notificationsWsConnect()
{
    const QString& dsToken
        = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9."
          "eyJpZCI6IjMyZmJhYWU5LTQ2YjQtNDBlMi1hOTUyLTkwOGMxOGI2MDc5MiIsImlhdCI6MTc2Njk2NDg0OH0."
          "t8muPDXWbmnbc1E8LmOcXXWvEVkJgOY1aDb1OYj2YJw";

    const QString& dsUrl = "ws://127.0.0.1:3333/ws/notifications";

    NotificationWs* notificationWs = new NotificationWs(dsUrl, dsToken);

    NotificationManager* notificationManager = NotificationManager::instance();

    notificationManager->attach(notificationWs);
}
