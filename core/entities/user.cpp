#include "user.h"

User::User() {}

QString User::email() const {
    return _email;
}

void User::setEmail( const QString& newEmail ) {

    if (_email == newEmail) {
        return;
    }

    _email = newEmail;

    emit emailChanged();
}

QString User::name() const {
    return _name;
}

void User::setName( const QString& newName ) {

    if (_name == newName) {
        return;
    }

    _name = newName;

    emit nameChanged();
}

QString User::avatarUrl() const {
    return _avatarUrl;
}

void User::setAvatarUrl( const QString& newAvatarUrl ) {

    if ( _avatarUrl == newAvatarUrl ) {
        return;
    }

    _avatarUrl = newAvatarUrl;

    emit avatarUrlChanged();
}
