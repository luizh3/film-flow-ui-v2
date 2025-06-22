#include "authcontroller.h"

#include <manager/applicationmanager.h>

#include <network/response/response.h>
#include <network/endpoint/authendpoint.h>

#include <entities/signup.h>
#include <entities/signin.h>

void AuthController::signIn(const QString& password, const QString& email)
{
    SignIn signIn;
    signIn.setPassword( password );
    signIn.setEmail( email );

    std::unique_ptr<Response> response( AuthEndpoint().signIn( signIn ) );

    if( !response || !response->isStatusValid() ) {
        emit error( "Fail on loggin" );
        return;
    }

    ApplicationManager::instance().setSession( Session::fromJson( response->data() ) );

    emit success();
}

void AuthController::signUp(const SignUp* signUp)
{
    std::unique_ptr<Response> response( AuthEndpoint().signUp( signUp ) );

    if( !response || !response->isStatusValid() ) {
        emit error( "Fail on register" );
        return;
    }

    emit success();
}
