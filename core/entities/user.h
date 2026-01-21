#ifndef USER_H
#define USER_H

#include <QObject>
#include <QQmlEngine>

#include <core_global.h>

class CORE_EXPORT User : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY( QString email READ email WRITE setEmail NOTIFY emailChanged FINAL )
    Q_PROPERTY( QString name READ name WRITE setName NOTIFY nameChanged FINAL )
    Q_PROPERTY( QString avatarUrl READ avatarUrl WRITE setAvatarUrl NOTIFY avatarUrlChanged FINAL )
public:
    User();
    User(const User *user);

    QString email() const;

    void setEmail( const QString &newEmail );

    QString name() const;
    void setName(const QString &newName);

    QString avatarUrl() const;
    void setAvatarUrl(const QString &newAvatarUrl);

signals:
    void emailChanged();
    void nameChanged();
    void avatarUrlChanged();

private:
    QString _email;
    QString _name;
    QString _avatarUrl;
};

#endif // USER_H
