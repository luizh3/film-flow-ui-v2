#include "applicationcontroller.h"

#include <network/response/response.h>

#include <network/endpoint/filmflowconfigendpoint.h>

#include <manager/applicationmanager.h>

#include <entities/configs.h>

#include <QDebug>

ApplicationController::ApplicationController()
    : _filmFlowConfigEndpoint{new FilmFlowConfigEndpoint(ApplicationManager::instance().session())}
{}

ApplicationController::~ApplicationController() = default;

void ApplicationController::configs()
{
    qInfo() << "ApplicationController::configs";

    std::unique_ptr<Response> response(_filmFlowConfigEndpoint->configs());

    if (!response || !response->isStatusValid()) {
        emit error("Fail on get configurations");
        return;
    }

    ApplicationManager::instance().setConfigs(Configs::fromJson(response->data()));

    emit success();

    qInfo() << "ApplicationController::configs";
}
