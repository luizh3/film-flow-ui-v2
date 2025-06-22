#include "homecontrol.h"

#include <core/manager/applicationmanager.h>
#include <core/entities/sectionsconfig.h>
#include <core/entities/configs.h>

Q_DECLARE_METATYPE(SectionsConfig*)
Q_DECLARE_METATYPE( QList<SectionsConfig*> );

void HomeControl::doStart() {

    emit sectionsChanged( QVariant::fromValue( ApplicationManager::instance().configs()->sectionsConfig() ) );

}
