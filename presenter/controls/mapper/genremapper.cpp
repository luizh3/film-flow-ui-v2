#include "genremapper.h"

#include <core/model/entities/genre.h>

#include "genremodel.h"

GenreModel *GenreMapper::toModel(const Genre *genre)
{
    if (!genre) {
        return nullptr;
    }

    return new GenreModel(genre->id(), genre->name());
}

QList<GenreModel *> GenreMapper::toModels(const QList<Genre *> &genres)
{
    QList<GenreModel *> genresModel = {};

    std::transform(genres.cbegin(),
                   genres.cend(),
                   std::back_inserter(genresModel),
                   [](const Genre *genre) { return GenreMapper::toModel(genre); });

    return genresModel;
}
