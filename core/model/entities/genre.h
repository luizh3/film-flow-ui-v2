#ifndef GENRE_H
#define GENRE_H

#include <QString>

#include <core_global.h>

class QJsonObject;
class CORE_EXPORT Genre
{
public: 
    Genre();
    explicit Genre( const int id, const QString& name );

    int id() const;
    void setId(int newId);

    QString name() const;
    void setName(const QString &newName);

    static Genre* fromJson( const QJsonObject& jsonDocument );

private:
    int _id;
    QString _name;
};

#endif // GENRE_H
