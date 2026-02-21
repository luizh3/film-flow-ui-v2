#include "genremodel.h"

GenreModel::GenreModel()
    : _id{0}
    , _name{QStringLiteral("")}
{}

GenreModel::GenreModel(const int id, const QString &name)
    : _id{id}
    , _name{name}
{}

int GenreModel::id() const
{
    return _id;
}

void GenreModel::setId(int newId)
{
    if (_id == newId) {
        return;
    }

    _id = newId;
    emit idChanged();
}

QString GenreModel::name() const
{
    return _name;
}

void GenreModel::setName(const QString &newName)
{
    if (_name == newName) {
        return;
    }
    _name = newName;
    emit nameChanged();
}
