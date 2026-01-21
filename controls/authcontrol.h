#ifndef AUTHCONTROL_H
#define AUTHCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include "control.h"

#include <controls_global.h>

#include <core/entities/signup.h>

class CONTROLS_EXPORT AuthControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    Q_INVOKABLE void signIn(const QString& password, const QString& email);
    Q_INVOKABLE void signUp(const SignUp* signUp);
signals:
    void success();
    void error();
private slots:
    void configs() const;
};

#endif // AUTHCONTROL_H
