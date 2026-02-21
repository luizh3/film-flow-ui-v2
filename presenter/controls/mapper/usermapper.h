#ifndef USERMAPPER_H
#define USERMAPPER_H

class User;
class UserModel;
class UserMapper
{
public:
    static UserModel* toModel(const User* user);
};

#endif // USERMAPPER_H
