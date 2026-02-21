#ifndef USERMODEL_H
#define USERMODEL_H

#include <QObject>

#include <models_global.h>

class MODELS_EXPORT UserModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString email READ email WRITE setEmail NOTIFY emailChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString avatarUrl READ avatarUrl WRITE setAvatarUrl NOTIFY avatarUrlChanged FINAL)
public:
    UserModel();
    UserModel(QString email, QString name, QString avatarUrl);

    QString email() const;
    void setEmail(const QString &newEmail);

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

#endif // USERMODEL_H
