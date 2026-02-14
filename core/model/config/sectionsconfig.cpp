#include "sectionsconfig.h"

#include <QJsonObject>

SectionsConfig::SectionsConfig() :
    _key{QStringLiteral("")},
    _name{QStringLiteral("")},
    _tpProgram{TypeProgramEnum::UNKNOW}{}

SectionsConfig::SectionsConfig(const TypeProgramEnum tpProgram, const QString& name, const QString& key) :
    _key{key},
    _name{name},
    _tpProgram{tpProgram}
{}

QString SectionsConfig::key() const
{
    return _key;
}

void SectionsConfig::setKey(const QString &newKey)
{
    _key = newKey;
}

QString SectionsConfig::name() const
{
    return _name;
}

void SectionsConfig::setName(const QString &newName)
{
    _name = newName;
}

TypeProgramEnum SectionsConfig::tpProgram() const
{
    return _tpProgram;
}

void SectionsConfig::setTpProgram(TypeProgramEnum newTpProgram)
{
    _tpProgram = newTpProgram;
}

SectionsConfig *SectionsConfig::fromJson(const QJsonObject& jsonObject)
{
    return new SectionsConfig(
        TypeProgram::fromString( jsonObject["type"].toString() ),
        jsonObject["name"].toString(),
        jsonObject["key"].toString()
    );
}
