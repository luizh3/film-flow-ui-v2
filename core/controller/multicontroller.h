#ifndef MULTICONTROLLER_H
#define MULTICONTROLLER_H

#include <QObject>

#include <QFuture>
#include <core_global.h>

class SearchMoviesResult;
class MovieInformation;
class MultiRequest;
class MultiDetailsRequest;
class PaginationRequest;
class ReviewsResult;
class FilmFlowMultiEndpoint;
class CORE_EXPORT MultiController : public QObject
{
public:
    MultiController();
    ~MultiController();

    QFuture<SearchMoviesResult*> find(const MultiRequest& request);
    QFuture<MovieInformation*> findById(const int id, const MultiDetailsRequest& request);
    QFuture<ReviewsResult*> findAllReviewsByIdMovie(const int id, const PaginationRequest* request);

    void cancel();

private:
    std::unique_ptr<FilmFlowMultiEndpoint> _filmFlowMultiEndpoint;
};

#endif // MULTICONTROLLER_H
