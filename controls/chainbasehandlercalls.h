#ifndef CHAINBASEHANDLERCALLS_H
#define CHAINBASEHANDLERCALLS_H

#include "chainhandlercalls.h"

class ChainBaseHandlerCalls : public ChainHandlerCalls
{
public:
    ChainBaseHandlerCalls();
    ChainHandlerCalls* next() override;
    void setNext(ChainHandlerCalls* next) override;
    void toastSuccess(const QString& message) override;
    void toastError(const QString& message) override;
    void toastWarning(const QString& message) override;
    void languageChanged() override;

private:
    ChainHandlerCalls* _next;
};

#endif // CHAINBASEHANDLERCALLS_H
