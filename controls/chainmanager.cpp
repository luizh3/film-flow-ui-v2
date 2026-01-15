#include "chainmanager.h"

ChainManager &ChainManager::instance()
{
    static ChainManager chainManager;
    return chainManager;
}

void ChainManager::add(ChainHandlerCalls *handler)
{
    if (!_handlers.isEmpty()) {
        handler->setNext(_handlers.last());
    }

    _handlers.append(handler);
}

void ChainManager::remove(ChainHandlerCalls *handler)
{
    if (!handler) {
        return;
    }

    for (ChainHandlerCalls *current : _handlers) {
        if (current->next() == handler) {
            current->setNext(handler->next());
            break;
        }
    }

    _handlers.removeOne(handler);
}
