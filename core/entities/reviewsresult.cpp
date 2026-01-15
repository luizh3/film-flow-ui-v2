#include "reviewsresult.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "pagination.h"
#include "review.h"

ReviewsResult::~ReviewsResult()
{
    qDeleteAll(_reviews);
    delete _pagination;
}

ReviewsResult::ReviewsResult()
    : _reviews{}
    , _pagination{nullptr}
{}

ReviewsResult::ReviewsResult(Pagination *pagination, QList<Review *> reviews)
    : _reviews{reviews}
    , _pagination{pagination}
{}

QList<Review *> ReviewsResult::reviews() const
{
    return _reviews;
}

void ReviewsResult::setReviews(const QList<Review *> &newReviews)
{
    _reviews = newReviews;
}

Pagination *ReviewsResult::pagination() const
{
    return _pagination;
}

void ReviewsResult::setPagination(Pagination *newPagination)
{
    _pagination = newPagination;
}

ReviewsResult *ReviewsResult::fromJson(const QJsonDocument &jsonDocument)
{
    QList<Review *> reviews = {};

    const QJsonArray reviewsArray = jsonDocument["reviews"].toArray();

    for (const QJsonValue &&reviewValue : reviewsArray) {
        reviews.append(Review::fromJson(reviewValue.toObject()));
    }

    return new ReviewsResult(Pagination::fromJson(jsonDocument.object()), reviews);
}
