#ifndef SIGNINREQUEST_H
#define SIGNINREQUEST_H

#include <QString>

class QJsonDocument;
class SignInRequest
{
public:
    SignInRequest();

    QString password() const;
    void setPassword(const QString &newPassword);

    QString email() const;
    void setEmail(const QString &newEmail);

    QJsonDocument toJson() const;

private:
    QString _password;
    QString _email;
};

#endif // SIGNINREQUEST_H
