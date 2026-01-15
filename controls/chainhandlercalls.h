#ifndef CHAINHANDLERCALLS_H
#define CHAINHANDLERCALLS_H

#include <QString>

class ChainHandlerCalls
{
public:
    virtual ChainHandlerCalls* next() = 0;
    virtual void setNext(ChainHandlerCalls* next) = 0;
    virtual void toastSuccess(const QString& message) = 0;
    virtual void toastError(const QString& message) = 0;
    virtual void toastWarning(const QString& message) = 0;
    virtual void languageChanged() = 0;
};

#endif // CHAINHANDLERCALLS_H
