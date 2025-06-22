#include "emailvalidator.h"

#include <QDebug>

#include <helper/regex/regexhelper.h>

QValidator::State EmailValidator::validate( QString& value, int& position) const
{
    _error = "";

    const bool isValid = RegexHelper::isEmailValid( value );

    if( value.isEmpty() ) {
        _error = "Empty is not allowed";
        return QValidator::State::Intermediate;
    }

    if( isValid ) {
        return QValidator::State::Acceptable;
    }

    _error = "E-mail not in the expected standard: example@gmail.com";

    return QValidator::State::Intermediate;

}
