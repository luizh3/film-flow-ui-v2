#ifndef FILMFLOWNOTIFICATIONENDPOINT_H
#define FILMFLOWNOTIFICATIONENDPOINT_H

#include "filmflowendpoint.h"

#include <QFuture>

class Response;
class Notification;
class PaginationRequest;
class FilmFlowNotificationEndpoint : public FilmFlowEndpoint
{
public:
    FilmFlowNotificationEndpoint(const Session* session);

    QFuture<Response*> findAll(const PaginationRequest* request);
};

#endif // FILMFLOWNOTIFICATIONENDPOINT_H
