#include "passwordvalidator.h"

#include <helper/regex/regexhelper.h>

PasswordValidator::PasswordValidator() :
    RangeValidator( 8, 20 ),
    _tpValidation{PasswordValidator::DEFAULT},
    _repeatPassword{QStringLiteral("")}
{}

QValidator::State PasswordValidator::validDefault( QString &value, int& position) const
{
    _error = "";

    if (value.isEmpty()) {
        _error = tr("Empty is not allowed");
        return QValidator::State::Intermediate;
    }

    QValidator::State state = RangeValidator::validate( value, position );

    if( state != QValidator::State::Acceptable ) {
        return state;
    }

    const bool isValid = RegexHelper::isPasswordValid( value );

    if( isValid ) {
        return QValidator::State::Acceptable;
    }

    _error = tr("The password must be at least 8 characters long. \nInclude an uppercase and "
                "lowercase letter. \nIt must include a special symbol (e.g., !@#$%^&*).");

    return QValidator::State::Intermediate;
}

QValidator::State PasswordValidator::validRepeat( const QString &value ) const
{

    _error = "";

    if (value.isEmpty()) {
        _error = tr("Empty is not allowed");
        return QValidator::State::Intermediate;
    }

    const bool isValid = value == _repeatPassword;

    if( isValid ) {
        return QValidator::State::Acceptable;
    }

    _error = tr("Password don't match");

    return QValidator::State::Intermediate;

}

QValidator::State PasswordValidator::validate( QString& value, int& position ) const {

    Q_UNUSED( position );

    switch( _tpValidation ) {
    case PasswordValidator::REPEAT:
        return validRepeat(value);
    default:
        return validDefault(value, position);
    }
}

PasswordValidator::TypeValidation PasswordValidator::tpValidation() const {
    return _tpValidation;
}

void PasswordValidator::setTpValidation( TypeValidation newTpValidation )
{

    if (_tpValidation == newTpValidation) {
        return;
    }

    _tpValidation = newTpValidation;
    emit tpValidationChanged();
}

QString PasswordValidator::repeatPassword() const
{
    return _repeatPassword;
}

void PasswordValidator::setRepeatPassword(const QString &newRepeatPassword)
{
    if (_repeatPassword == newRepeatPassword) {
        return;
    }

    _repeatPassword = newRepeatPassword;
    emit repeatPasswordChanged();
}

