#include "authendpoint.h"

#include <network/httpclient.h>

#include <network/request/signinrequest.h>
#include <network/request/signuprequest.h>

namespace {
constexpr const char* DS_ENDPOINT_SIGN_IN = "http://localhost:3333/api/auth/sign-in";
constexpr const char* DS_ENDPOINT_SIGN_UP = "http://localhost:3333/api/auth/sign-up";
}

Response* AuthEndpoint::signIn(const SignInRequest& signIn)
{
    return HttpClient().post(QUrl(DS_ENDPOINT_SIGN_IN), signIn.toJson());
}

Response* AuthEndpoint::signUp(const SignUpRequest* signUp)
{
    return HttpClient().post(QUrl(DS_ENDPOINT_SIGN_UP), signUp->toJson());
}
