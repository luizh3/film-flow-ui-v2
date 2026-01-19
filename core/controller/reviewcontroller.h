#ifndef REVIEWCONTROLLER_H
#define REVIEWCONTROLLER_H

#include <QObject>

#include <core_global.h>

#include <network/endpoint/filmflowreviewendpoint.h>

class Review;
class PaginationRequest;
class ReviewsResult;
class CORE_EXPORT ReviewController : public QObject
{
    Q_OBJECT
public:
    ReviewController();

    void create(const Review* review);
    void update(const Review* review);
    ReviewsResult* findAll(const PaginationRequest* paginationRequest);
signals:
    void error(const QString& message);
    void success(Review* review);

private:
    FilmFlowReviewEndpoint _filmFlowReviewEndpoint;
};

#endif // REVIEWCONTROLLER_H
