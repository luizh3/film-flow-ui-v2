#ifndef REVIEWCONTROLLER_H
#define REVIEWCONTROLLER_H

#include <QObject>

#include <core_global.h>

class Review;
class PaginationRequest;
class ReviewsResult;
class CORE_EXPORT ReviewController : public QObject
{
    Q_OBJECT
public:
    void create(const Review* review);
    void update(const Review* review);
    ReviewsResult* findAll(const PaginationRequest* paginationRequest);
signals:
    void error(const QString& message);
    void success(Review* review);
};

#endif // REVIEWCONTROLLER_H
