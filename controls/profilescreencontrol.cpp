#include "profilescreencontrol.h"

#include <core/manager/applicationmanager.h>

#include <core/entities/session.h>

ProfileScreenControl::ProfileScreenControl()
    : _user{nullptr}
{}

void ProfileScreenControl::doStart()
{
    // TODO make a request to get data for this screen

    _user.reset(new User(ApplicationManager::instance().session()->user()));

    emit userChanged(QVariant::fromValue(_user.get()));
}
