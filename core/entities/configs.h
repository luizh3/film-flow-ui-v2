#ifndef CONFIGS_H
#define CONFIGS_H

#include <QList>

#include <core_global.h>

class QJsonDocument;
class ProgramConfig;
class SectionsConfig;
class CORE_EXPORT Configs
{
public:
    ~Configs();

    Configs();
    explicit Configs(const QList<ProgramConfig*>& programsConfig,
                     const QList<SectionsConfig*>& sectionsConfig);

    QList<SectionsConfig*> sectionsConfig() const;
    void setSectionsConfig(const QList<SectionsConfig*>& newSectionsConfig);

    QList<ProgramConfig*> programsConfig() const;
    void setProgramsConfig(const QList<ProgramConfig*>& newProgramsConfig);

    static Configs* fromJson(const QJsonDocument& jsonDocument);

private:
    QList<ProgramConfig*> _programsConfig;
    QList<SectionsConfig*> _sectionsConfig;
};

#endif // CONFIGS_H
