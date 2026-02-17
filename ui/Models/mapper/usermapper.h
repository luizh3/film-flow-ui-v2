#ifndef USERMAPPER_H
#define USERMAPPER_H

#include <models_global.h>

class User;
class UserModel;
class MODELS_EXPORT UserMapper
{
public:
    static UserModel* toModel(const User* user);
};

#endif // USERMAPPER_H
