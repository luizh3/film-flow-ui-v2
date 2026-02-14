#ifndef GENREMAPPER_H
#define GENREMAPPER_H

#include <QList>

#include <models_global.h>

class Genre;
class GenreModel;
class MODELS_EXPORT GenreMapper
{
public:
    static GenreModel* toModel(const Genre* genre);
    static QList<GenreModel*> toModels(const QList<Genre*>& genres);
};

#endif // GENREMAPPER_H
