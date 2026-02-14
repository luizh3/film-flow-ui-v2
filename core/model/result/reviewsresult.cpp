#include "reviewsresult.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "paginationresult.h"
#include <model/entities/review.h>

ReviewsResult::~ReviewsResult()
{
    qDeleteAll(_reviews);
    delete _pagination;
}

ReviewsResult::ReviewsResult()
    : _pagination{nullptr}
    , _reviews{}
{}

ReviewsResult::ReviewsResult(PaginationResult *pagination, QList<Review *> reviews)
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

PaginationResult *ReviewsResult::pagination() const
{
    return _pagination;
}

void ReviewsResult::setPagination(PaginationResult *newPagination)
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

    return new ReviewsResult(PaginationResult::fromJson(jsonDocument.object()), reviews);
}
