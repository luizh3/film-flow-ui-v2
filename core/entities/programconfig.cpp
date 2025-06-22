#include "programconfig.h"

#include <QJsonArray>
#include <QJsonObject>

#include "genre.h"

ProgramConfig::~ProgramConfig() {
    qDeleteAll( _genres );
}

ProgramConfig::ProgramConfig()
    : _tpProgram{TypeProgramEnum::UNKNOW}
    , _genres{{}}
{}

ProgramConfig::ProgramConfig(const TypeProgramEnum tpProgram, const QList<Genre*>& genres)
    : _tpProgram{tpProgram}
    , _genres{genres}
{}

TypeProgramEnum ProgramConfig::tpProgram() const
{
    return _tpProgram;
}

void ProgramConfig::setTpProgram(TypeProgramEnum newTpProgram)
{
    _tpProgram = newTpProgram;
}

QList<Genre*> ProgramConfig::genres() const
{
    return _genres;
}

void ProgramConfig::setGenres(const QList<Genre*> &newGenres)
{
    _genres = newGenres;
}

ProgramConfig* ProgramConfig::fromJson(const QJsonObject& jsonDocument)
{
    const QJsonArray genresArray = jsonDocument["genres"].toArray();

    QList<Genre*> genres = {};

    for( const QJsonValue&& current : genresArray ) {
        genres.append( Genre::fromJson( current.toObject() ) );
    }

    return new ProgramConfig( TypeProgramEnum::UNKNOW, genres );
}
