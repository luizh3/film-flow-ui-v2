#include "applicationcontroller.h"

#include <network/response/response.h>

#include <network/endpoint/filmflowconfigendpoint.h>

#include <manager/applicationmanager.h>

#include <entities/configs.h>

#include <QDebug>

void ApplicationController::configs()
{
    qInfo() << "ApplicationController::configs";

    std::unique_ptr<Response> response(FilmFlowConfigEndpoint().configs());

    if (!response || !response->isStatusValid()) {
        emit error("Fail on get configurations");
        return;
    }

    ApplicationManager::instance().setConfigs(Configs::fromJson(response->data()));

    emit success();

    qInfo() << "ApplicationController::configs";
}
