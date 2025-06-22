#include "movieinformation.h"

#include <QJsonObject>

MovieInformation::MovieInformation() :
    _average{0.00},
    _title{QStringLiteral("")},
    _id{QStringLiteral("")},
    _backdropUrl{QStringLiteral("")},
    _posterUrl{QStringLiteral("")},
    _overview{QStringLiteral("")},
    _release{QStringLiteral("")},
    _genresId{{}}
{}

MovieInformation::MovieInformation(
    double average,
    const QString &title,
    const QString &id,
    const QString &backdropUrl,
    const QString &posterUrl,
    const QString &overview,
    const QString &release,
    const QList<int>& genresId) :
    _average{average},
    _title{title},
    _id{id},
    _backdropUrl{backdropUrl},
    _posterUrl{posterUrl},
    _overview{overview},
    _release{release},
    _genresId{genresId}
{}

double MovieInformation::average() const
{
    return _average;
}

void MovieInformation::setAverage(double newAverage)
{
    _average = newAverage;
}

QString MovieInformation::title() const
{
    return _title;
}

void MovieInformation::setTitle(const QString &newTitle)
{
    _title = newTitle;
}

QString MovieInformation::id() const
{
    return _id;
}

void MovieInformation::setId(const QString &newId)
{
    _id = newId;
}

QString MovieInformation::backdropUrl() const
{
    return _backdropUrl;
}

void MovieInformation::setBackdropUrl(const QString &newBackdropUrl)
{
    _backdropUrl = newBackdropUrl;
}

QString MovieInformation::posterUrl() const
{
    return _posterUrl;
}

void MovieInformation::setPosterUrl(const QString &newPosterUrl)
{
    _posterUrl = newPosterUrl;
}

QString MovieInformation::overview() const
{
    return _overview;
}

void MovieInformation::setOverview(const QString &newOverview)
{
    _overview = newOverview;
}

QString MovieInformation::release() const
{
    return _release;
}

void MovieInformation::setRelease(const QString &newRelease)
{
    _release = newRelease;
}

QList<int> MovieInformation::genresId() const
{
    return _genresId;
}

void MovieInformation::setGenresId(const QList<int> &newGenresId)
{
    _genresId = newGenresId;
}

MovieInformation *MovieInformation::fromJson(const QJsonObject &jsonObject) {
    return new MovieInformation(
        jsonObject["average"].toDouble(),
        jsonObject["title"].toString(),
        jsonObject["id"].toString(),
        jsonObject["backdropUrl"].toString(),
        jsonObject["posterUrl"].toString(),
        jsonObject["overview"].toString(),
        jsonObject["release"].toString(),
        jsonObject["genresId"].toVariant().value<QList<int>>()
    );
}
