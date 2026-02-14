#ifndef SIGNUP_H
#define SIGNUP_H

#include <QObject>
#include <QQmlEngine>

#include <core_global.h>

class CORE_EXPORT SignUp : public QObject {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY( QString password READ password WRITE setPassword NOTIFY passwordChanged FINAL )
    Q_PROPERTY( QString email READ email WRITE setEmail NOTIFY emailChanged FINAL )
    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged FINAL )
public:

    SignUp();

    QString password() const;
    void setPassword( const QString& newPassword );

    QString email() const;
    void setEmail( const QString& newEmail);

    QString name() const;
    void setName( const QString& newName );

    QJsonDocument toJson() const;

signals:
    void passwordChanged();
    void emailChanged();
    void nameChanged();

private:
    QString _password;
    QString _email;
    QString _name;
};

#endif // SIGNUP_H
