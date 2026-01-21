#include "session.h"

Session::Session() :
    _token{ QStringLiteral("") },
    _user{ nullptr }{}

QString Session::token() const {
    return _token;
}

void Session::setToken( const QString& newToken) {
    _token = newToken;
}

User* Session::user() const {
    return _user;
}

void Session::setUser( User* newUser) {
    _user = newUser;
}

Session* Session::fromJson( const QJsonDocument& jsonDocument ) {

    Session* session = new Session();
    session->setToken( jsonDocument["accessToken"].toString() );

    User* user = new User();
    user->setAvatarUrl( jsonDocument["avatarUrl"].toString() );
    user->setName(jsonDocument["name"].toString());
    user->setEmail( jsonDocument["email"].toString() );

    session->setUser( user );

    return session;

}
