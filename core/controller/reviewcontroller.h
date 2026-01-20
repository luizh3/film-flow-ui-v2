#ifndef REVIEWCONTROLLER_H
#define REVIEWCONTROLLER_H

#include <QObject>

#include <core_global.h>

class Review;
class PaginationRequest;
class ReviewsResult;
class FilmFlowReviewEndpoint;
class CORE_EXPORT ReviewController : public QObject
{
    Q_OBJECT
public:
    ~ReviewController();
    ReviewController();

    void create(const Review* review);
    void update(const Review* review);
    ReviewsResult* findAll(const PaginationRequest* paginationRequest);

    void cancel() const;

signals:
    void error(const QString& message);
    void success(Review* review);

private:
    std::unique_ptr<FilmFlowReviewEndpoint> _filmFlowReviewEndpoint;
};

#endif // REVIEWCONTROLLER_H
