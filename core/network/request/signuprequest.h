#ifndef SIGNUPREQUEST_H
#define SIGNUPREQUEST_H

#include <core_global.h>

#include <QJsonDocument>

class CORE_EXPORT SignUpRequest
{
public:
    SignUpRequest();
    SignUpRequest(const QString &name, const QString &email, const QString &password);

    QJsonDocument toJson() const;

    QString name() const;
    void setName(const QString &newName);

    QString email() const;
    void setEmail(const QString &newEmail);

    QString password() const;
    void setPassword(const QString &newPassword);

private:
    QString _name;
    QString _email;
    QString _password;
};

#endif // SIGNUPREQUEST_H
