#ifndef CONFIGS_H
#define CONFIGS_H

#include <QList>

#include <core_global.h>

#include "typeprogramenum.h"

class QJsonDocument;
class ProgramConfig;
class SectionsConfig;
class CORE_EXPORT Configs
{
public:
    ~Configs();

    Configs();
    explicit Configs(const QMap<TypeProgramEnum, ProgramConfig*>& programsConfigByType,
                     const QList<SectionsConfig*>& sectionsConfig);

    QList<SectionsConfig*> sectionsConfig() const;
    void setSectionsConfig(const QList<SectionsConfig*>& newSectionsConfig);

    static Configs* fromJson(const QJsonDocument& jsonDocument);

    ProgramConfig* programConfigByType(const TypeProgramEnum tpProgram) const;

private:
    QMap<TypeProgramEnum, ProgramConfig*> _programsConfigByType;
    QList<SectionsConfig*> _sectionsConfig;
};

#endif // CONFIGS_H
