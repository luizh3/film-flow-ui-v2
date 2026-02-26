#include "themeinit.h"

#include <qqml.h>

#include "manager/themecolormanager.h"

void Theme::registerQmlTypes()
{
    qmlRegisterSingletonInstance("ThemeColorManager",
                                 1,
                                 0,
                                 "ThemeColorManager",
                                 ThemeColorManager::instance());
}
