#include "authcontrol.h"

#include <QDebug>

#include <core/controller/authcontroller.h>
#include <core/controller/applicationcontroller.h>

void AuthControl::signIn(const QString& password, const QString& email)
{
    qInfo() << "AuthControl::authenticate";

    AuthController controller;

    QObject::connect(&controller, &AuthController::error, this, &AuthControl::error);
    QObject::connect(&controller, &AuthController::success, this, &AuthControl::configs);
    QObject::connect(&controller, &AuthController::error, this, [this](const QString& message) {
        toastError(message);
        emit error();
    });

    controller.signIn( password, email );

    qInfo() << "AuthControl::authenticate";
}

void AuthControl::signUp(const SignUp* signUp)
{
    qInfo() << "AuthControl::authenticate";

    AuthController controller;

    QObject::connect( &controller, &AuthController::success, this, &AuthControl::success );
    QObject::connect(&controller, &AuthController::error, this, [this](const QString& message) {
        toastError(message);
        emit error();
    });

    controller.signUp(signUp);

    qInfo() << "AuthControl::authenticate";
}

void AuthControl::configs() const
{
    qInfo() << "AuthControl::configs";

    ApplicationController controller;

    QObject::connect(&controller, &ApplicationController::error, this, &AuthControl::error);
    QObject::connect(&controller, &ApplicationController::success, this, &AuthControl::success);

    controller.configs();

    qInfo() << "AuthControl::configs";
}
