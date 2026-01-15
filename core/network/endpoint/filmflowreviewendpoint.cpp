#include "filmflowreviewendpoint.h"

#include <QUrlQuery>

#include <entities/review.h>

#include <network/httpclient.h>
#include <network/request/paginationrequest.h>

namespace {
constexpr const char *REVIEW_ENDPOINT = "/review";
constexpr const char *REVIEW_LIKE = "/review/%0/like";
}

Response *FilmFlowReviewEndpoint::create(const Review *review)
{
    QUrl baseUrl(toEndpoint(REVIEW_ENDPOINT));

    return HttpClient().post(baseUrl, review->toJson(), _headers);
}

Response *FilmFlowReviewEndpoint::update(const Review *review)
{
    QUrl baseUrl(toEndpoint(REVIEW_ENDPOINT));

    return HttpClient().put(baseUrl, review->toJson(), _headers);
}

Response *FilmFlowReviewEndpoint::findAll(const PaginationRequest *request) const
{
    QUrl baseUrl(toEndpoint(REVIEW_ENDPOINT));

    baseUrl.setQuery(request->toQuerys());

    return HttpClient().get(baseUrl, _headers);
}

Response *FilmFlowReviewEndpoint::like(const QString &reviewId) const
{
    QUrl baseUrl(toEndpoint(QString(REVIEW_LIKE).arg(reviewId)));

    return HttpClient().post(baseUrl, {}, _headers);
}

Response *FilmFlowReviewEndpoint::unlike(const QString &reviewId) const
{
    QUrl baseUrl(toEndpoint(QString(REVIEW_LIKE).arg(reviewId)));

    return HttpClient().deleteResource(baseUrl, _headers);
}
