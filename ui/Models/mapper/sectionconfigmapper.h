#ifndef SECTIONCONFIGMAPPER_H
#define SECTIONCONFIGMAPPER_H

#include <QList>

#include <models_global.h>

class SectionsConfig;
class SectionConfigModel;
class MODELS_EXPORT SectionConfigMapper
{
public:
    static SectionConfigModel* toModel(const SectionsConfig* sectionsConfig);
    static QList<SectionConfigModel*> toModels(const QList<SectionsConfig*>& sectionsConfig);
};

#endif // SECTIONCONFIGMAPPER_H
