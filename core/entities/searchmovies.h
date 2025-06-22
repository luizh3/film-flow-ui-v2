#ifndef SEARCHMOVIES_H
#define SEARCHMOVIES_H

#include <QList>

#include <core_global.h>

class Pagination;
class MovieInformation;
class QJsonDocument;

class CORE_EXPORT SearchMovies
{
public:
    ~SearchMovies();

    SearchMovies();
    SearchMovies(Pagination *pagination, const QList<MovieInformation *> &movies);

    Pagination *pagination() const;
    void setPagination(Pagination *newPagination);

    QList<MovieInformation *> movies() const;
    void setMovies(const QList<MovieInformation *> &newMovies);

    static SearchMovies* fromJson( const QJsonDocument& jsonDocument );

private:
    Pagination* _pagination;
    QList<MovieInformation*> _movies;
};

#endif // SEARCHMOVIES_H
