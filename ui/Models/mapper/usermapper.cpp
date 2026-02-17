#include "usermapper.h"

#include <core/model/entities/user.h>

#include "usermodel.h"

UserModel *UserMapper::toModel(const User *user)
{
    if (!user) {
        return nullptr;
    }

    return new UserModel(user->email(), user->name(), user->avatarUrl());
}
