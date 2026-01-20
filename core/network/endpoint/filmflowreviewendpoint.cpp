#include "filmflowreviewendpoint.h"

#include <QUrlQuery>

#include <entities/review.h>

#include <network/httpclient.h>
#include <network/request/paginationrequest.h>

namespace {
constexpr const char *REVIEW_ENDPOINT = "/review";
constexpr const char *REVIEW_LIKE = "/review/%0/like";
}

FilmFlowReviewEndpoint::FilmFlowReviewEndpoint(const Session *session)
    : FilmFlowEndpoint(session)
{}

Response *FilmFlowReviewEndpoint::create(const Review *review)
{
    QUrl baseUrl(toEndpoint(REVIEW_ENDPOINT));

    return _httpClient->post(baseUrl, review->toJson(), _headers);
}

Response *FilmFlowReviewEndpoint::update(const Review *review)
{
    QUrl baseUrl(toEndpoint(REVIEW_ENDPOINT));

    return _httpClient->put(baseUrl, review->toJson(), _headers);
}

Response *FilmFlowReviewEndpoint::findAll(const PaginationRequest *request)
{
    QUrl baseUrl(toEndpoint(REVIEW_ENDPOINT));

    baseUrl.setQuery(request->toQuerys());

    return _httpClient->get(baseUrl, _headers);
}

Response *FilmFlowReviewEndpoint::like(const QString &reviewId)
{
    QUrl baseUrl(toEndpoint(QString(REVIEW_LIKE).arg(reviewId)));

    return _httpClient->post(baseUrl, {}, _headers);
}

Response *FilmFlowReviewEndpoint::unlike(const QString &reviewId)
{
    QUrl baseUrl(toEndpoint(QString(REVIEW_LIKE).arg(reviewId)));

    return _httpClient->deleteResource(baseUrl, _headers);
}

