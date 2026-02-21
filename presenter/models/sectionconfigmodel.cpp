#include "sectionconfigmodel.h"

SectionConfigModel::SectionConfigModel()
    : _tpProgram{PresenterTypeProgramEnum::UNKNOW}
    , _name{QStringLiteral("")}
    , _key{QStringLiteral("")}
{}

SectionConfigModel::SectionConfigModel(PresenterTypeProgramEnum tpProgram, QString name, QString key)
    : _tpProgram(tpProgram)
    , _name(std::move(name))
    , _key(std::move(key))
{}

PresenterTypeProgramEnum SectionConfigModel::tpProgram() const
{
    return _tpProgram;
}

void SectionConfigModel::setTpProgram(PresenterTypeProgramEnum newTpProgram)
{
    if (_tpProgram == newTpProgram) {
        return;
    }

    _tpProgram = newTpProgram;
    emit tpProgramChanged();
}

QString SectionConfigModel::name() const
{
    return _name;
}

void SectionConfigModel::setName(const QString &newName)
{
    if (_name == newName) {
        return;
    }

    _name = newName;
    emit nameChanged();
}

QString SectionConfigModel::key() const
{
    return _key;
}

void SectionConfigModel::setKey(const QString &newKey)
{
    if (_key == newKey) {
        return;
    }

    _key = newKey;
    emit keyChanged();
}
