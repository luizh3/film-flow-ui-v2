#ifndef AUTHCONTROL_H
#define AUTHCONTROL_H

#include <QObject>
#include <QQmlEngine>
#include <controls_global.h>

#include <core/entities/signup.h>

class CONTROLS_EXPORT AuthControl : public QObject {
    Q_OBJECT
    QML_ELEMENT
public:
    Q_INVOKABLE void signIn( const QString& password, const QString& email ) const;
    Q_INVOKABLE void signUp( const SignUp* signUp ) const;
    Q_INVOKABLE void configs() const;
signals:
    void success();
    void error( const QString& message );
};

#endif // AUTHCONTROL_H
