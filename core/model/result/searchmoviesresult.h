#ifndef SEARCHMOVIESRESULT_H
#define SEARCHMOVIESRESULT_H

#include <QList>

#include <core_global.h>

class PaginationResult;
class MovieInformation;
class QJsonDocument;

class CORE_EXPORT SearchMoviesResult
{
public:
    ~SearchMoviesResult();

    SearchMoviesResult();
    SearchMoviesResult(PaginationResult *pagination, const QList<MovieInformation *> &movies);

    PaginationResult *pagination() const;
    void setPagination(PaginationResult *newPagination);

    QList<MovieInformation *> movies() const;
    void setMovies(const QList<MovieInformation *> &newMovies);

    static SearchMoviesResult *fromJson(const QJsonDocument &jsonDocument);

private:
    PaginationResult *_pagination;
    QList<MovieInformation*> _movies;
};

#endif // SEARCHMOVIESRESULT_H
