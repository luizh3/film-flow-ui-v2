#ifndef SIGNUPMODEL_H
#define SIGNUPMODEL_H

#include <QObject>
#include <QQmlEngine>

#include <models_global.h>

class MODELS_EXPORT SignUpModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged FINAL)
    Q_PROPERTY(QString password READ password WRITE setPassword NOTIFY passwordChanged FINAL)
public:
    SignUpModel();

    QString name() const;
    void setName(const QString &newName);

    QString email() const;
    void setEmail(const QString &newEmail);

    QString password() const;
    void setPassword(const QString &newPassword);

signals:
    void nameChanged();
    void emailChanged();
    void passwordChanged();

private:
    QString _name;
    QString _email;
    QString _password;
};

#endif // SIGNUPMODEL_H
