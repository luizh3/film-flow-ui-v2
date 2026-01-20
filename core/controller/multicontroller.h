#ifndef MULTICONTROLLER_H
#define MULTICONTROLLER_H

#include <QObject>

#include <core_global.h>

class SearchMovies;
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

    SearchMovies* find(const MultiRequest& request);
    MovieInformation* findById(const int id, const MultiDetailsRequest& request);
    ReviewsResult* findAllReviewsByIdMovie(const int id, const PaginationRequest* request);

    void cancel();

private:
    std::unique_ptr<FilmFlowMultiEndpoint> _filmFlowMultiEndpoint;
};

#endif // MULTICONTROLLER_H
