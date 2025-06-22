#ifndef SIGNIN_H
#define SIGNIN_H

#include <QString>

class QJsonDocument;
class SignIn {
public:
    SignIn();

    QString password() const;
    void setPassword(const QString &newPassword);

    QString email() const;
    void setEmail(const QString &newEmail);

    QJsonDocument toJson() const;

private:
    QString _password;
    QString _email;
};

#endif // SIGNIN_H
