#include "signupmapper.h"

#include <core/network/request/signuprequest.h>

#include "signupmodel.h"

SignUpRequest *SignUpMapper::toRequest(const SignUpModel *signUpModel)
{
    return new SignUpRequest(signUpModel->name(), signUpModel->email(), signUpModel->password());
}
