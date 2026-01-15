#ifndef CHAINMANAGER_H
#define CHAINMANAGER_H

#include <QList>

#include "chainhandlercalls.h"

class ChainManager
{
public:
    static ChainManager& instance();

    void add(ChainHandlerCalls* handler);
    void remove(ChainHandlerCalls* handler);

private:
    QList<ChainHandlerCalls*> _handlers;
};

#endif // CHAINMANAGER_H
