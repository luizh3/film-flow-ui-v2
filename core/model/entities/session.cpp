#include "session.h"

Session::Session()
    : _user{nullptr}
    , _token{QStringLiteral("")}
{}

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

    session->setUser(User::fromJson(jsonDocument));

    return session;

}
