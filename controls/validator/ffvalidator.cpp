#include "ffvalidator.h"

FFValidator::FFValidator() :
    _error(QStringLiteral("")){}

QString FFValidator::error() const
{
    return _error;
}

void FFValidator::setError(const QString &newError)
{
    if (_error == newError) {
        return;
    }
    _error = newError;
    emit errorChanged();
}
