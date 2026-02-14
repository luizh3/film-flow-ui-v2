#include "sectionconfigmapper.h"

#include <core/model/config/sectionsconfig.h>

#include "sectionconfigmodel.h"

SectionConfigModel *SectionConfigMapper::toModel(const SectionsConfig *sectionsConfig)
{
    return new SectionConfigModel(sectionsConfig->tpProgram(),
                                  sectionsConfig->name(),
                                  sectionsConfig->key());
}

QList<SectionConfigModel *> SectionConfigMapper::toModels(
    const QList<SectionsConfig *> &sectionsConfig)
{
    QList<SectionConfigModel *> sectionsConfigModel = {};

    std::transform(sectionsConfig.cbegin(),
                   sectionsConfig.cend(),
                   std::back_inserter(sectionsConfigModel),
                   [](const SectionsConfig *sectionConfig) {
                       return SectionConfigMapper::toModel(sectionConfig);
                   });

    return sectionsConfigModel;
}
