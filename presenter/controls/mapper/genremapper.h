#ifndef GENREMAPPER_H
#define GENREMAPPER_H

#include <QList>

class Genre;
class GenreModel;
class GenreMapper
{
public:
    static GenreModel* toModel(const Genre* genre);
    static QList<GenreModel*> toModels(const QList<Genre*>& genres);
};

#endif // GENREMAPPER_H
