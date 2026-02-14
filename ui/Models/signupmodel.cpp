#include "signupmodel.h"

SignUpModel::SignUpModel()
    : _password(QStringLiteral(""))
    , _email(QStringLiteral(""))
    , _name(QStringLiteral(""))
{}

QString SignUpModel::name() const
{
    return _name;
}

void SignUpModel::setName(const QString &newName)
{
    if (_name == newName) {
        return;
    }

    _name = newName;
    emit nameChanged();
}

QString SignUpModel::email() const
{
    return _email;
}

void SignUpModel::setEmail(const QString &newEmail)
{
    if (_email == newEmail) {
        return;
    }

    _email = newEmail;
    emit emailChanged();
}

QString SignUpModel::password() const
{
    return _password;
}

void SignUpModel::setPassword(const QString &newPassword)
{
    if (_password == newPassword) {
        return;
    }

    _password = newPassword;
    emit passwordChanged();
}
