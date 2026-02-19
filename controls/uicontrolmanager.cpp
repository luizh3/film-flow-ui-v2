#include "uicontrolmanager.h"

#include <core/manager/applicationmanager.h>
#include <core/model/entities/session.h>

#include <ui/models/mapper/usermapper.h>

UiControlManager &UiControlManager::instance()
{
    static UiControlManager uiControlManager;
    return uiControlManager;
}

UiControlManager::UiControlManager()
    : _user{nullptr}
    , _languageManager{}
{}

UserModel *UiControlManager::user()
{
    if (!_user) {
        _user.reset(UserMapper::toModel(ApplicationManager::instance().session()->user()));
    }

    return _user.get();
}

LanguageManager &UiControlManager::languageManager()
{
    return _languageManager;
}
