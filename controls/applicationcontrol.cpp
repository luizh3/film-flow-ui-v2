#include "applicationcontrol.h"

#include <core/controller/applicationcontroller.h>

#include <core/manager/applicationmanager.h>
#include <core/manager/notificationmanager.h>
#include <core/model/entities/session.h>

#include <core/model/entities/notificationreviewlike.h>

void ApplicationControl::doStart()
{
    notificationsWsConnect();
}

void ApplicationControl::notificationsWsConnect()
{
    const QString& dsUrl = "ws://127.0.0.1:3333/ws/notifications";

    NotificationWs* notificationWs
        = new NotificationWs(dsUrl, ApplicationManager::instance().session()->token());

    NotificationManager* notificationManager = NotificationManager::instance();

    notificationManager->attach(notificationWs);
}

