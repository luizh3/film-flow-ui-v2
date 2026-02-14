#include "configs.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "sectionsconfig.h"
#include "programconfig.h"

Configs::~Configs()
{
    qDeleteAll(_programsConfigByType);
    qDeleteAll(_sectionsConfig);
}

Configs::Configs()
    : _programsConfigByType{{}}
    , _sectionsConfig{{}}
{}

Configs::Configs(const QMap<TypeProgramEnum, ProgramConfig*>& programsConfigByType,
                 const QList<SectionsConfig*>& sectionsConfig)
    : _programsConfigByType{programsConfigByType}
    , _sectionsConfig{sectionsConfig}
{}

QList<SectionsConfig*> Configs::sectionsConfig() const
{
    return _sectionsConfig;
}

void Configs::setSectionsConfig(const QList<SectionsConfig*>& newSectionsConfig)
{
    _sectionsConfig = newSectionsConfig;
}

Configs* Configs::fromJson(const QJsonDocument& jsonDocument)
{

    QJsonArray sectionsArray = jsonDocument["sections"].toArray();

    QList<SectionsConfig*> sectionsConfig = {};

    for( const QJsonValue&& programValue : sectionsArray ) {
        sectionsConfig.append( SectionsConfig::fromJson( programValue.toObject() ) );
    }

    QMap<TypeProgramEnum, ProgramConfig*> programsConfigByType = {};

    // TODO Alterar a maneira como vem da API
    if( !jsonDocument["movie"].isNull() ) {
        ProgramConfig* program = ProgramConfig::fromJson( jsonDocument["movie"].toObject() );
        program->setTpProgram( TypeProgramEnum::MOVIE );
        programsConfigByType.insert(TypeProgramEnum::MOVIE, program);
    }

    if( !jsonDocument["tv"].isNull() ) {
        ProgramConfig* program = ProgramConfig::fromJson( jsonDocument["tv"].toObject() );
        program->setTpProgram( TypeProgramEnum::TV );
        programsConfigByType.insert(TypeProgramEnum::TV, program);
    }

    return new Configs(programsConfigByType, sectionsConfig);
}

ProgramConfig* Configs::programConfigByType(const TypeProgramEnum tpProgram) const
{
    return _programsConfigByType.value(tpProgram);
}
