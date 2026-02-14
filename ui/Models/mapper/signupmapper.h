#ifndef SIGNUPMAPPER_H
#define SIGNUPMAPPER_H

#include <models_global.h>

class SignUpRequest;
class SignUpModel;
class MODELS_EXPORT SignUpMapper
{
public:
    static SignUpRequest *toRequest(const SignUpModel *signUpModel);
};

#endif // SIGNUPMAPPER_H
