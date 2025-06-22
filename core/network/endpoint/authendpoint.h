#ifndef AUTHENDPOINT_H
#define AUTHENDPOINT_H

#include <entities/session.h>

class SignUp;
class SignIn;
class Response;

class AuthEndpoint {
public:
    Response* signIn( const SignIn& signIn );
    Response* signUp( const SignUp* signUp );
};

#endif // AUTHENDPOINT_H
