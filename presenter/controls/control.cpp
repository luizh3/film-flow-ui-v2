#include "control.h"

#include "chainmanager.h"

Control::Control()
{
    ChainManager::instance().add(this);
}

Control::~Control()
{
    ChainManager::instance().remove(this);
}
