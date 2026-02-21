#ifndef GENREMODEL_H
#define GENREMODEL_H

#include <QObject>

#include <models_global.h>

class MODELS_EXPORT GenreModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
public:
    GenreModel();
    explicit GenreModel(const int id, const QString &name);

    int id() const;
    void setId(int newId);

    QString name() const;
    void setName(const QString &newName);

signals:
    void idChanged();
    void nameChanged();

private:
    int _id;
    QString _name;
};

#endif // GENREMODEL_H
