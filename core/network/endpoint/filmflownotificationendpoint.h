#ifndef FILMFLOWNOTIFICATIONENDPOINT_H
#define FILMFLOWNOTIFICATIONENDPOINT_H

#include "filmflowendpoint.h"

class Response;
class Notification;
class PaginationRequest;
class filmflownotificationendpoint : public FilmFlowEndpoint
{
public:
    Response* findAll(const PaginationRequest* request);
};

#endif // FILMFLOWNOTIFICATIONENDPOINT_H
