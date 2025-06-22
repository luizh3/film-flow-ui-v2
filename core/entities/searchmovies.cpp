#include "searchmovies.h"

#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include "pagination.h"
#include "movieinformation.h"

SearchMovies::~SearchMovies()
{
    qDeleteAll(_movies);
    delete _pagination;
}

SearchMovies::SearchMovies() :
    _pagination{nullptr},
    _movies{{}}
{}

SearchMovies::SearchMovies(Pagination *pagination, const QList<MovieInformation *> &movies)
    : _pagination{pagination}
    , _movies{movies}
{}

Pagination *SearchMovies::pagination() const
{
    return _pagination;
}

void SearchMovies::setPagination(Pagination *newPagination)
{
    _pagination = newPagination;
}

QList<MovieInformation*> SearchMovies::movies() const
{
    return _movies;
}

void SearchMovies::setMovies(const QList<MovieInformation *> &newMovies)
{
    _movies = newMovies;
}

SearchMovies *SearchMovies::fromJson(const QJsonDocument &jsonDocument)
{

    QList<MovieInformation*> movies = {};

    const QJsonArray moviesArray = jsonDocument["movies"].toArray();

    for( const QJsonValue&& movieValue : moviesArray ) {
        movies.append( MovieInformation::fromJson( movieValue.toObject() ) );
    }

    return new SearchMovies(
        Pagination::fromJson( jsonDocument["pagination"].toObject() ),
        movies
    );
}
