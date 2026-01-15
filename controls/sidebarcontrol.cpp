#include "sidebarcontrol.h"

void SideBarControl::languageChanged()
{
    emit Control::notifierLanguageChanged();

    Control::languageChanged();
}
