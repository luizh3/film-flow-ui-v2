#include "notificationcontroller.h"

#include <network/response/response.h>

#include <manager/applicationmanager.h>

#include <entities/notificationsresult.h>

NotificationController::NotificationController()
    : _filmFlowNotificationEndpoint{ApplicationManager::instance().session()}
{}

NotificationsResult *NotificationController::findAll(const PaginationRequest *paginationRequest)
{
    std::unique_ptr<Response> response(_filmFlowNotificationEndpoint.findAll(paginationRequest));

    return NotificationsResult::fromJson(response->data());
}
