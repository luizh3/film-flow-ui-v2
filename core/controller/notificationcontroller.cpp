#include "notificationcontroller.h"

#include <network/endpoint/filmflownotificationendpoint.h>
#include <network/response/response.h>

#include <manager/applicationmanager.h>

#include <model/result/notificationsresult.h>

#include <helper/taskrunhelper.h>

NotificationController::NotificationController()
    : _filmFlowNotificationEndpoint{
          new FilmFlowNotificationEndpoint(ApplicationManager::instance().session())}
{}

NotificationController::~NotificationController() = default;

QFuture<NotificationsResult *> NotificationController::findAll(
    const PaginationRequest *paginationRequest)
{
    return TaskRunHelper::promiseAsync<NotificationsResult, Response>(
        _filmFlowNotificationEndpoint->findAll(paginationRequest));
}

void NotificationController::cancel()
{
    _filmFlowNotificationEndpoint->cancel();
}
