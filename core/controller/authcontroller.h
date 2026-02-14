#ifndef AUTHCONTROLLER_H
#define AUTHCONTROLLER_H

#include <QObject>

#include <core_global.h>

class SignUpRequest;

class CORE_EXPORT AuthController : public QObject
{
    Q_OBJECT
public:
    void signIn( const QString& password, const QString& email );
    void signUp(const SignUpRequest* signUp);
signals:
    void success();
    void error( const QString& message );
};

#endif // AUTHCONTROLLER_H
