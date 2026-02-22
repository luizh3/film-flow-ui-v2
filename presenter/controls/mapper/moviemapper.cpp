#include "moviemapper.h"

#include <core/model/entities/movieinformation.h>

#include "genremapper.h"
#include "moviemodel.h"
#include "reviewmapper.h"
#include "typeprogramenummapper.h"

MovieModel *MovieMapper::toModel(const MovieInformation *movieInformation)
{
    return new MovieModel(ReviewMapper::toModel(movieInformation->myReview()),
                          movieInformation->average(),
                          TypeProgramEnumMapper::toModel(movieInformation->tpProgram()),
                          movieInformation->title(),
                          movieInformation->id(),
                          movieInformation->backdropUrl(),
                          movieInformation->posterUrl(),
                          movieInformation->overview(),
                          movieInformation->releaseDate().toString("dd/MM/yyyy"),
                          GenreMapper::toModels(movieInformation->genres()));
}

QList<MovieModel *> MovieMapper::toModels(const QList<MovieInformation *> &movies)
{
    QList<MovieModel *> moviesModel = {};

    std::transform(movies.cbegin(),
                   movies.cend(),
                   std::back_inserter(moviesModel),
                   [](const MovieInformation *movie) { return MovieMapper::toModel(movie); });

    return moviesModel;
}
