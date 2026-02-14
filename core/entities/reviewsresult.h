#ifndef REVIEWSRESULT_H
#define REVIEWSRESULT_H

#include <QList>

#include "core_global.h"

class Pagination;
class Review;
class QJsonDocument;
class CORE_EXPORT ReviewsResult
{
public:
    ReviewsResult();
    ~ReviewsResult();

    ReviewsResult(Pagination *pagination, QList<Review *> reviews);

    QList<Review *> reviews() const;
    void setReviews(const QList<Review *> &newReviews);

    Pagination *pagination() const;
    void setPagination(Pagination *newPagination);

    static ReviewsResult *fromJson(const QJsonDocument &jsonDocument);

private:
    Pagination *_pagination;
    QList<Review *> _reviews;
};

#endif // REVIEWSRESULT_H
