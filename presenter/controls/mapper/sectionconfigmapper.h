#ifndef SECTIONCONFIGMAPPER_H
#define SECTIONCONFIGMAPPER_H

#include <QList>

class SectionsConfig;
class SectionConfigModel;
class SectionConfigMapper
{
public:
    static SectionConfigModel* toModel(const SectionsConfig* sectionsConfig);
    static QList<SectionConfigModel*> toModels(const QList<SectionsConfig*>& sectionsConfig);
};

#endif // SECTIONCONFIGMAPPER_H
