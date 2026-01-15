#include "chainbasehandlercalls.h"

ChainBaseHandlerCalls::ChainBaseHandlerCalls()
    : _next{nullptr}
{}

ChainHandlerCalls* ChainBaseHandlerCalls::next()
{
    return _next;
}

void ChainBaseHandlerCalls::setNext(ChainHandlerCalls *next)
{
    _next = next;
}

void ChainBaseHandlerCalls::toastSuccess(const QString& message)
{
    if (_next) {
        _next->toastSuccess(message);
    }
}

void ChainBaseHandlerCalls::toastError(const QString& message)
{
    if (_next) {
        _next->toastError(message);
    }
}

void ChainBaseHandlerCalls::toastWarning(const QString& message)
{
    if (_next) {
        _next->toastWarning(message);
    }
}

void ChainBaseHandlerCalls::languageChanged()
{
    if (_next) {
        _next->languageChanged();
    }
}
