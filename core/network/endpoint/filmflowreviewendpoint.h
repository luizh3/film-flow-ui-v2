#ifndef FILMFLOWREVIEWENDPOINT_H
#define FILMFLOWREVIEWENDPOINT_H

#include "filmflowendpoint.h"

#include <network/httpclient.h>

class Response;
class Review;
class PaginationRequest;
class FilmFlowReviewEndpoint : public FilmFlowEndpoint
{
public:
    FilmFlowReviewEndpoint(const Session* session);

    Response* create(const Review* review);
    Response* update(const Review* review);
    Response* findAll(const PaginationRequest* request);
    Response* like(const QString& reviewId);
    Response* unlike(const QString& reviewId);

    void cancel();

private:
    HttpClient _httpClient;
};

#endif // FILMFLOWREVIEWENDPOINT_H
