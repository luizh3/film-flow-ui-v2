#include "configs.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "sectionsconfig.h"
#include "programconfig.h"

Configs::~Configs()
{
    qDeleteAll(_programsConfig);
    qDeleteAll(_sectionsConfig);
}

Configs::Configs() :
    _programsConfig{{}},
    _sectionsConfig{{}}
{}

Configs::Configs(const QList<ProgramConfig*>& programsConfig,
                 const QList<SectionsConfig*>& sectionsConfig)
    : _programsConfig{programsConfig}
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

QList<ProgramConfig*> Configs::programsConfig() const
{
    return _programsConfig;
}

void Configs::setProgramsConfig(const QList<ProgramConfig*>& newProgramsConfig)
{
    _programsConfig = newProgramsConfig;
}

Configs* Configs::fromJson(const QJsonDocument& jsonDocument)
{

    QJsonArray sectionsArray = jsonDocument["sections"].toArray();

    QList<SectionsConfig*> sectionsConfig = {};

    for( const QJsonValue&& programValue : sectionsArray ) {
        sectionsConfig.append( SectionsConfig::fromJson( programValue.toObject() ) );
    }

    QList<ProgramConfig*> programsConfig = {};

    // TODO Alterar a maneira como vem da API
    if( !jsonDocument["movie"].isNull() ) {
        ProgramConfig* program = ProgramConfig::fromJson( jsonDocument["movie"].toObject() );
        program->setTpProgram( TypeProgramEnum::MOVIE );
        programsConfig.append( program );
    }

    if( !jsonDocument["tv"].isNull() ) {
        ProgramConfig* program = ProgramConfig::fromJson( jsonDocument["tv"].toObject() );
        program->setTpProgram( TypeProgramEnum::TV );
        programsConfig.append( program );
    }

    return new Configs( programsConfig, sectionsConfig );
}
