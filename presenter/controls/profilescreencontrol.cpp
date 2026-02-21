#include "profilescreencontrol.h"

#include <core/manager/applicationmanager.h>

#include <core/model/entities/session.h>
#include <core/model/entities/user.h>

#include "mapper/usermapper.h"

ProfileScreenControl::ProfileScreenControl()
    : _user{nullptr}
{}

void ProfileScreenControl::doStart()
{
    // TODO make a request to get data for this screen

    _user.reset(UserMapper::toModel(ApplicationManager::instance().session()->user()));

    emit userChanged(QVariant::fromValue(_user.get()));
}
