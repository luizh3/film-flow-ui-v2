#include "genre.h"

#include <QJsonObject>

Genre::Genre() :
    _id{0},
    _name{QStringLiteral("")}{}

Genre::Genre(const int id, const QString& name) :
    _id{id},
    _name{name}{}

int Genre::id() const
{
    return _id;
}

void Genre::setId(int newId)
{
    _id = newId;
}

QString Genre::name() const
{
    return _name;
}

void Genre::setName(const QString &newName)
{
    _name = newName;
}

Genre* Genre::fromJson(const QJsonObject& jsonObject)
{
    return new Genre( jsonObject["id"].toInt(), jsonObject["name"].toString() );
}
