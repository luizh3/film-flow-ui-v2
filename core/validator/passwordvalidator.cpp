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

    QValidator::State state = RangeValidator::validate( value, position );

    if( state != QValidator::State::Acceptable ) {
        return state;
    }

    const bool isValid = RegexHelper::isPasswordValid( value );

    if( value.isEmpty() ) {
        _error = "Empty is not allowed";
        return QValidator::State::Intermediate;
    }

    if( isValid ) {
        return QValidator::State::Acceptable;
    }

    _error = "A senha deve ter no mínimo 8 caracteres. \nIncluir uma letra maiúscula e minúscula. \nDeve incluir um símbolo especial (ex: !@#$%^&*).";

    return QValidator::State::Intermediate;
}

QValidator::State PasswordValidator::validRepeat( const QString &value ) const
{

    _error = "";

    const bool isValid = value == _repeatPassword;

    if( isValid ) {
        return QValidator::State::Acceptable;
    }

    _error = "Password don't match";

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

