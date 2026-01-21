#include "profilescreencontrol.h"

#include <core/manager/applicationmanager.h>

#include <core/entities/session.h>

ProfileScreenControl::ProfileScreenControl()
    : _user{nullptr}
{}

void ProfileScreenControl::doStart()
{
    _user.reset(new User(ApplicationManager::instance().session()->user()));

    emit userChanged(QVariant::fromValue(_user.get()));
}
