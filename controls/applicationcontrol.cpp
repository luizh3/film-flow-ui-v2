#include "applicationcontrol.h"

#include <core/controller/applicationcontroller.h>

#include <entities/session.h>
#include <manager/applicationmanager.h>
#include <manager/notificationmanager.h>

#include <entities/notificationreviewlike.h>

void ApplicationControl::doStart()
{
    configs();
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

void ApplicationControl::configs() const
{
    qInfo() << "ApplicationControl::configs";

    ApplicationController controller;

    QObject::connect(&controller, &ApplicationController::error, this, &ApplicationControl::error);
    QObject::connect(&controller,
                     &ApplicationController::success,
                     this,
                     &ApplicationControl::success);

    controller.configs();

    qInfo() << "ApplicationControl::configs";
}
