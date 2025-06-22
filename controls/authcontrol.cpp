#include "authcontrol.h"

#include <QDebug>

#include <core/controller/authcontroller.h>
#include <core/controller/applicationcontroller.h>

void AuthControl::signIn( const QString& password, const QString& email ) const {

    qInfo() << "AuthControl::authenticate";

    AuthController controller;

    QObject::connect( &controller, &AuthController::error, this, &AuthControl::error );
    QObject::connect( &controller, &AuthController::success, this, &AuthControl::configs );

    controller.signIn( password, email );

    qInfo() << "AuthControl::authenticate";
}

void AuthControl::signUp( const SignUp* signUp ) const {

    qInfo() << "AuthControl::authenticate";

    AuthController controller;

    QObject::connect( &controller, &AuthController::error, this, &AuthControl::error );
    QObject::connect( &controller, &AuthController::success, this, &AuthControl::success );

    controller.signUp( signUp );

    qInfo() << "AuthControl::authenticate";

}

void AuthControl::configs() const {

    qInfo() << "AuthControl::configs";

    ApplicationController controller;

    QObject::connect( &controller, &ApplicationController::error, this, &AuthControl::error );
    QObject::connect( &controller, &ApplicationController::success, this, &AuthControl::success );

    controller.configs();

    qInfo() << "AuthControl::configs";

}
