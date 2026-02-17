#include "user.h"

#include <QJsonDocument>
#include <QJsonObject>

User::User()
    : _email{QStringLiteral("")}
    , _avatarUrl{QStringLiteral("")}
    , _name{QStringLiteral("")}
{}

User::User(const User* user)
    : _email{user->email()}
    , _avatarUrl{user->avatarUrl()}
    , _name{user->name()}
{}

User::User(const QString& email, const QString& name, const QString& avatarUrl, const QString& id)
    : _email(email)
    , _name(name)
    , _avatarUrl(avatarUrl)
    , _id{id}
{}

QString User::email() const {
    return _email;
}

void User::setEmail( const QString& newEmail ) {
    _email = newEmail;
}

QString User::name() const {
    return _name;
}

void User::setName( const QString& newName ) {
    _name = newName;
}

QString User::avatarUrl() const {
    return _avatarUrl;
}

void User::setAvatarUrl( const QString& newAvatarUrl ) {
    _avatarUrl = newAvatarUrl;
}

QString User::id() const
{
    return _id;
}

void User::setId(const QString& newId)
{
    _id = newId;
}

User* User::fromJson(const QJsonDocument& jsonDocument)
{
    return User::fromJson(jsonDocument.object());
}

User* User::fromJson(const QJsonObject& jsonObject)
{
    User* user = new User(jsonObject["email"].toString(),
                          jsonObject["name"].toString(),
                          jsonObject["avatarUrl"].toString(),
                          jsonObject["id"].toString());

    return user;
}
