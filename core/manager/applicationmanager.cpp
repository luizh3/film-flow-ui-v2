#include "applicationmanager.h"

#include <entities/session.h>
#include <entities/configs.h>

ApplicationManager::~ApplicationManager() {
    delete _session;
    delete _configs;
}

ApplicationManager::ApplicationManager() :
    _session{nullptr},
    _configs{nullptr}
{}

ApplicationManager& ApplicationManager::instance() {
    static ApplicationManager applicationManager;
    return applicationManager;
}

Session *ApplicationManager::session() const
{
    return _session;
}

void ApplicationManager::setSession(Session *newSession)
{
    _session = newSession;
}

Configs *ApplicationManager::configs() const
{
    return _configs;
}

void ApplicationManager::setConfigs(Configs *newConfigs)
{
    _configs = newConfigs;
}
