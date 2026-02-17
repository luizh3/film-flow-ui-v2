#include "usermodel.h"

UserModel::UserModel()
    : _email{QStringLiteral("")}
    , _name{QStringLiteral("")}
    , _avatarUrl{QStringLiteral("")}
{}

UserModel::UserModel(QString email, QString name, QString avatarUrl)
    : _email(std::move(email))
    , _name(std::move(name))
    , _avatarUrl(std::move(avatarUrl))
{}

QString UserModel::email() const
{
    return _email;
}

void UserModel::setEmail(const QString &newEmail)
{
    if (_email == newEmail) {
        return;
    }

    _email = newEmail;
    emit emailChanged();
}

QString UserModel::name() const
{
    return _name;
}

void UserModel::setName(const QString &newName)
{
    if (_name == newName) {
        return;
    }

    _name = newName;
    emit nameChanged();
}

QString UserModel::avatarUrl() const
{
    return _avatarUrl;
}

void UserModel::setAvatarUrl(const QString &newAvatarUrl)
{
    if (_avatarUrl == newAvatarUrl) {
        return;
    }

    _avatarUrl = newAvatarUrl;
    emit avatarUrlChanged();
}
