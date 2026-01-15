#include "programconfig.h"

#include <QJsonArray>
#include <QJsonObject>

#include "genre.h"

ProgramConfig::~ProgramConfig() {
    qDeleteAll(_genresById);
    _genresById.clear();
}

ProgramConfig::ProgramConfig()
    : _tpProgram{TypeProgramEnum::UNKNOW}
    , _genresById{{}}
{}

ProgramConfig::ProgramConfig(const TypeProgramEnum tpProgram, const QMap<int, Genre*>& genres)
    : _tpProgram{tpProgram}
    , _genresById{genres}
{}

TypeProgramEnum ProgramConfig::tpProgram() const
{
    return _tpProgram;
}

void ProgramConfig::setTpProgram(TypeProgramEnum newTpProgram)
{
    _tpProgram = newTpProgram;
}

ProgramConfig* ProgramConfig::fromJson(const QJsonObject& jsonDocument)
{
    const QJsonArray genresArray = jsonDocument["genres"].toArray();

    QMap<int, Genre*> genres = {};

    for( const QJsonValue&& current : genresArray ) {
        Genre* genre = Genre::fromJson(current.toObject());
        genres.insert(genre->id(), genre);
    }

    return new ProgramConfig( TypeProgramEnum::UNKNOW, genres );
}

QMap<int, Genre*> ProgramConfig::genresById() const
{
    return _genresById;
}

void ProgramConfig::setGenresById(const QMap<int, Genre*>& newGenresById)
{
    _genresById = newGenresById;
}
