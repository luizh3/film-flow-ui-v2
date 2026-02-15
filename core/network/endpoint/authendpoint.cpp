#include "authendpoint.h"

#include <network/httpclient.h>

#include <network/request/signinrequest.h>
#include <network/request/signuprequest.h>

namespace {
constexpr const char* DS_ENDPOINT_SIGN_IN = "%0/auth/sign-in";
constexpr const char* DS_ENDPOINT_SIGN_UP = "%0/auth/sign-up";
}

Response* AuthEndpoint::signIn(const SignInRequest& signIn)
{
    return HttpClient()
        .post(QString(DS_ENDPOINT_SIGN_IN).arg(qEnvironmentVariable("FILM_FLOW_API_HOST")),
              signIn.toJson());
}

Response* AuthEndpoint::signUp(const SignUpRequest* signUp)
{
    return HttpClient()
        .post(QString(DS_ENDPOINT_SIGN_UP).arg(qEnvironmentVariable("FILM_FLOW_API_HOST")),
              signUp->toJson());
}
