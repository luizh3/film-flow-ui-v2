#ifndef USER_H
#define USER_H

#include <QString>

#include <core_global.h>

class QJsonObject;
class QJsonDocument;
class CORE_EXPORT User
{
public:
    User();
    User(const User *user);
    User(const QString &email,
         const QString &name,
         const QString &avatarUrl,
         const QString &id = QStringLiteral(""));

    QString email() const;
    void setEmail( const QString &newEmail );

    QString name() const;
    void setName(const QString &newName);

    QString avatarUrl() const;
    void setAvatarUrl(const QString &newAvatarUrl);

    QString id() const;
    void setId(const QString &newId);

    static User *fromJson(const QJsonDocument &jsonDocument);
    static User *fromJson(const QJsonObject &jsonObject);

private:
    QString _id;
    QString _email;
    QString _name;
    QString _avatarUrl;
};

#endif // USER_H
