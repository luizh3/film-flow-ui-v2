#ifndef FILMFLOWMULTIENDPOINT_H
#define FILMFLOWMULTIENDPOINT_H

#include "filmflowendpoint.h"

#include <network/httpclient.h>

class Response;
class MultiRequest;
class MultiDetailsRequest;
class PaginationRequest;
class FilmFlowMultiEndpoint : public FilmFlowEndpoint
{
public:
    FilmFlowMultiEndpoint(const Session* session);

    Response* find(const MultiRequest& request);
    Response* findById(const int id, const MultiDetailsRequest& request);
    Response* findAllReviewsByIdMovie(const int id, const PaginationRequest* request);
};

#endif // FILMFLOWMULTIENDPOINT_H
