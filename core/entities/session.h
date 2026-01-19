#ifndef SESSION_H
#define SESSION_H

#include <QJsonDocument>
#include <QString>

#include <core_global.h>

#include "user.h"

class CORE_EXPORT Session
{
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
