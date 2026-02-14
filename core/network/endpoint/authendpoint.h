#ifndef AUTHENDPOINT_H
#define AUTHENDPOINT_H

#include <model/entities/session.h>

class SignUpRequest;
class SignInRequest;
class Response;

class AuthEndpoint {
public:
    Response* signIn(const SignInRequest& signIn);
    Response* signUp(const SignUpRequest* signUp);
};

#endif // AUTHENDPOINT_H
