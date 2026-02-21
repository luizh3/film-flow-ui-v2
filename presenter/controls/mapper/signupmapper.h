#ifndef SIGNUPMAPPER_H
#define SIGNUPMAPPER_H

class SignUpRequest;
class SignUpModel;
class SignUpMapper
{
public:
    static SignUpRequest *toRequest(const SignUpModel *signUpModel);
};

#endif // SIGNUPMAPPER_H
