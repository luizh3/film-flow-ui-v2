#include "signup.h"

#include <QJsonObject>
#include <QJsonDocument>

SignUp::SignUp() :
    _password(QStringLiteral("")),
    _email(QStringLiteral("")),
    _name(QStringLiteral(""))
{}

QString SignUp::password() const
{
    return _password;
}

void SignUp::setPassword(const QString &newPassword)
{
    if (_password == newPassword) {
        return;
    }
    _password = newPassword;
    emit passwordChanged();
}

QString SignUp::email() const
{
    return _email;
}

void SignUp::setEmail(const QString &newEmail)
{
    if (_email == newEmail) {
        return;
    }
    _email = newEmail;
    emit emailChanged();
}

QString SignUp::name() const
{
    return _name;
}

void SignUp::setName(const QString &newName)
{
    if (_name == newName) {
        return;
    }
    _name = newName;
    emit nameChanged();
}

QJsonDocument SignUp::toJson() const {

    QJsonDocument jsonDocument;

    QJsonObject jsonObject;

    jsonObject["email"] = _email;
    jsonObject["name"] = _name;
    jsonObject["password"] = _password;

    jsonDocument.setObject( jsonObject );

    return std::move( jsonDocument );

}

