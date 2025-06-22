#include "signuprequest.h"

#include <QJsonObject>

SignUpRequest::SignUpRequest() {}

QJsonDocument SignUpRequest::toJson() const {

    QJsonDocument jsonDocument;

    QJsonObject jsonObject;

    jsonObject["email"] = _email;
    jsonObject["name"] = _name;
    jsonObject["password"] = _password;

    jsonDocument.setObject( jsonObject );

    return std::move( jsonDocument );

}

QString SignUpRequest::name() const
{
    return _name;
}

void SignUpRequest::setName(const QString &newName)
{
    _name = newName;
}

QString SignUpRequest::email() const
{
    return _email;
}

void SignUpRequest::setEmail(const QString &newEmail)
{
    _email = newEmail;
}

QString SignUpRequest::password() const
{
    return _password;
}

void SignUpRequest::setPassword(const QString &newPassword)
{
    _password = newPassword;
}
