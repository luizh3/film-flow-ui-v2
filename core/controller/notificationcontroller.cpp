#include "notificationcontroller.h"

#include <network/endpoint/filmflownotificationendpoint.h>
#include <network/response/response.h>

#include <entities/notificationsresult.h>

NotificationsResult *NotificationController::findAll(const PaginationRequest *paginationRequest)
{
    std::unique_ptr<Response> response(filmflownotificationendpoint().findAll(paginationRequest));

    return NotificationsResult::fromJson(response->data());
}
