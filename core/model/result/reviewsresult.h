#ifndef REVIEWSRESULT_H
#define REVIEWSRESULT_H

#include <QList>

#include "core_global.h"

class PaginationResult;
class Review;
class QJsonDocument;
class CORE_EXPORT ReviewsResult
{
public:
    ReviewsResult();
    ~ReviewsResult();

    ReviewsResult(PaginationResult *pagination, QList<Review *> reviews);

    QList<Review *> reviews() const;
    void setReviews(const QList<Review *> &newReviews);

    PaginationResult *pagination() const;
    void setPagination(PaginationResult *newPagination);

    static ReviewsResult *fromJson(const QJsonDocument &jsonDocument);

private:
    PaginationResult *_pagination;
    QList<Review *> _reviews;
};

#endif // REVIEWSRESULT_H
