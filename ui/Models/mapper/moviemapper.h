#ifndef MOVIEMAPPER_H
#define MOVIEMAPPER_H

#include <QList>

#include <models_global.h>

class MovieModel;
class MovieInformation;
class MODELS_EXPORT MovieMapper
{
public:
    static MovieModel* toModel(const MovieInformation* movieInformation);
    static QList<MovieModel*> toModels(const QList<MovieInformation*>& movies);
};

#endif // MOVIEMAPPER_H
