#ifndef MULTICONTROLLER_H
#define MULTICONTROLLER_H

#include <core_global.h>

#include <network/endpoint/filmflowmultiendpoint.h>

class SearchMovies;
class MovieInformation;
class MultiRequest;
class MultiDetailsRequest;
class PaginationRequest;
class ReviewsResult;
class CORE_EXPORT MultiController
{
public:
    MultiController();

    SearchMovies* find(const MultiRequest& request);
    MovieInformation* findById(const int id, const MultiDetailsRequest& request);
    ReviewsResult* findAllReviewsByIdMovie(const int id, const PaginationRequest* request);

    void cancel();

private:
    FilmFlowMultiEndpoint _filmFlowMultiEndpoint;
};

#endif // MULTICONTROLLER_H
