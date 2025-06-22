#ifndef SIGNUPREQUEST_H
#define SIGNUPREQUEST_H

#include <QString>

#include "request.h"

class SignUpRequest : public Request {
public:
    SignUpRequest();

    QJsonDocument toJson() const override;
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
