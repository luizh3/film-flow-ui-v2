#ifndef SESSION_H
#define SESSION_H

#include <QString>
#include <QJsonDocument>

#include "user.h"

class Session {
public:
    Session();

    QString token() const;
    void setToken( const QString& newToken );

    User* user() const;
    void setUser( User* newUser);

    static Session* fromJson( const QJsonDocument& jsonDocument );

private:
    QString _token;
    User* _user;
};

#endif // SESSION_H
