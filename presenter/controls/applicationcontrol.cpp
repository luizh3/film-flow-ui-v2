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
    const QString dsWebsocketUrl = qEnvironmentVariable("FILM_FLOW_WEBSOCKET_HOST");

    if (dsWebsocketUrl.isEmpty()) {
        qCritical() << "ApplicationControl::notificationsWsConnect host of websocket not founded!";
        return;
    }

    const QString& dsUrl = QString("ws://%0/ws/notifications").arg(dsWebsocketUrl);

    NotificationWs* notificationWs
        = new NotificationWs(dsUrl, ApplicationManager::instance().session()->token());

    NotificationManager* notificationManager = NotificationManager::instance();

    notificationManager->attach(notificationWs);
}

