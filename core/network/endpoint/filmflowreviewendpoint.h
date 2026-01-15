#ifndef FILMFLOWREVIEWENDPOINT_H
#define FILMFLOWREVIEWENDPOINT_H

#include "filmflowendpoint.h"

class Response;
class Review;
class PaginationRequest;
class FilmFlowReviewEndpoint : public FilmFlowEndpoint
{
public:
    Response* create(const Review* review);
    Response* update(const Review* review);
    Response* findAll(const PaginationRequest* request) const;
    Response* like(const QString& reviewId) const;
    Response* unlike(const QString& reviewId) const;
};

#endif // FILMFLOWREVIEWENDPOINT_H
