#include "homecontrol.h"

#include <core/manager/applicationmanager.h>
#include <core/model/config/configs.h>
#include <core/model/config/sectionsconfig.h>

#include "mapper/sectionconfigmapper.h"

HomeControl::~HomeControl()
{
    qDeleteAll(_sectionsConfig);
}

void HomeControl::doStart() {
    _sectionsConfig = SectionConfigMapper::toModels(
        ApplicationManager::instance().configs()->sectionsConfig());

    emit sectionsChanged(QVariant::fromValue(_sectionsConfig));
}
