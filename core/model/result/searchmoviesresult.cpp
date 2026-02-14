#include "searchmoviesresult.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "paginationresult.h"
#include <model/entities/movieinformation.h>

SearchMoviesResult::~SearchMoviesResult()
{
    qDeleteAll(_movies);
    delete _pagination;
}

SearchMoviesResult::SearchMoviesResult()
    : _pagination{nullptr}
    , _movies{{}}
{}

SearchMoviesResult::SearchMoviesResult(PaginationResult *pagination,
                                       const QList<MovieInformation *> &movies)
    : _pagination{pagination}
    , _movies{movies}
{}

PaginationResult *SearchMoviesResult::pagination() const
{
    return _pagination;
}

void SearchMoviesResult::setPagination(PaginationResult *newPagination)
{
    _pagination = newPagination;
}

QList<MovieInformation *> SearchMoviesResult::movies() const
{
    return _movies;
}

void SearchMoviesResult::setMovies(const QList<MovieInformation *> &newMovies)
{
    _movies = newMovies;
}

SearchMoviesResult *SearchMoviesResult::fromJson(const QJsonDocument &jsonDocument)
{

    QList<MovieInformation*> movies = {};

    const QJsonArray moviesArray = jsonDocument["movies"].toArray();

    for( const QJsonValue&& movieValue : moviesArray ) {
        movies.append( MovieInformation::fromJson( movieValue.toObject() ) );
    }

    return new SearchMoviesResult(PaginationResult::fromJson(jsonDocument.object()), movies);
}
