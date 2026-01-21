#include "notificationcontroller.h"

#include <network/endpoint/filmflownotificationendpoint.h>
#include <network/response/response.h>

#include <manager/applicationmanager.h>

#include <entities/notificationsresult.h>

NotificationController::NotificationController()
    : _filmFlowNotificationEndpoint{
          new FilmFlowNotificationEndpoint(ApplicationManager::instance().session())}
{}

NotificationController::~NotificationController() = default;

NotificationsResult *NotificationController::findAll(const PaginationRequest *paginationRequest)
{
    std::unique_ptr<Response> response(_filmFlowNotificationEndpoint->findAll(paginationRequest));

    if (!response) {
        return nullptr;
    }

    return NotificationsResult::fromJson(response->data());
}

void NotificationController::cancel()
{
    _filmFlowNotificationEndpoint->cancel();
}
