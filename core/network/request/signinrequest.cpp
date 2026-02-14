#include "signinrequest.h"

#include <QJsonObject>
#include <QJsonDocument>

SignInRequest::SignInRequest()
    : _email(QStringLiteral(""))
    , _password(QStringLiteral(""))
{}

QString SignInRequest::password() const
{
    return _password;
}

void SignInRequest::setPassword(const QString &newPassword)
{
    _password = newPassword;
}

QString SignInRequest::email() const
{
    return _email;
}

void SignInRequest::setEmail(const QString &newEmail)
{
    _email = newEmail;
}

QJsonDocument SignInRequest::toJson() const
{
    QJsonDocument jsonDocument;

    QJsonObject jsonObject;

    jsonObject["password"] = _password;
    jsonObject["email"] = _email;

    jsonDocument.setObject( jsonObject );

    return jsonDocument;
}
