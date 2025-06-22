#include "signin.h"

#include <QJsonObject>
#include <QJsonDocument>

SignIn::SignIn() :
    _email(QStringLiteral("")),
    _password(QStringLiteral(""))
{}

QString SignIn::password() const
{
    return _password;
}

void SignIn::setPassword(const QString &newPassword)
{
    _password = newPassword;
}

QString SignIn::email() const
{
    return _email;
}

void SignIn::setEmail(const QString &newEmail)
{
    _email = newEmail;
}

QJsonDocument SignIn::toJson() const {

    QJsonDocument jsonDocument;

    QJsonObject jsonObject;

    jsonObject["password"] = _password;
    jsonObject["email"] = _email;

    jsonDocument.setObject( jsonObject );

    return std::move( jsonDocument );

}
