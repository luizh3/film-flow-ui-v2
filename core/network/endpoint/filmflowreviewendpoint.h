#ifndef FILMFLOWREVIEWENDPOINT_H
#define FILMFLOWREVIEWENDPOINT_H

#include <QFuture>

#include "filmflowendpoint.h"

class Response;
class Review;
class PaginationRequest;
class FilmFlowReviewEndpoint : public FilmFlowEndpoint
{
public:
    FilmFlowReviewEndpoint(const Session* session);

    Response* create(const Review* review);
    Response* update(const Review* review);
    QFuture<Response*> findAll(const PaginationRequest* request);
    QFuture<Response*> like(const QString& reviewId);
    QFuture<Response*> unlike(const QString& reviewId);
};

#endif // FILMFLOWREVIEWENDPOINT_H
