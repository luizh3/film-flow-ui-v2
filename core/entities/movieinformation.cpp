#include "movieinformation.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "genre.h"

MovieInformation::MovieInformation()
    : _myReview{nullptr}
    , _average{0.00}
    , _tpProgram{TypeProgramEnum::UNKNOW}
    , _title{QStringLiteral("")}
    , _id{QStringLiteral("")}
    , _backdropUrl{QStringLiteral("")}
    , _posterUrl{QStringLiteral("")}
    , _overview{QStringLiteral("")}
    , _release{QStringLiteral("")}
    , _genres{}
{}

MovieInformation::MovieInformation(Review *myReview,
                                   double average,
                                   const TypeProgramEnum tpProgram,
                                   const QString &title,
                                   const QString &id,
                                   const QString &backdropUrl,
                                   const QString &posterUrl,
                                   const QString &overview,
                                   const QString &release,
                                   const QList<Genre *> &genres)
    : _myReview{myReview}
    , _average{average}
    , _tpProgram{tpProgram}
    , _title{title}
    , _id{id}
    , _backdropUrl{backdropUrl}
    , _posterUrl{posterUrl}
    , _overview{overview}
    , _release{release}
    , _genres{genres}
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

MovieInformation *MovieInformation::fromJson(const QJsonDocument &jsonDocument)
{
    return fromJson(jsonDocument.object());
}

MovieInformation *MovieInformation::fromJson(const QJsonObject &jsonObject) {
    QList<Genre *> genres = {};

    for (const QJsonValue &&genreValue : jsonObject["genres"].toArray()) {
        genres.append(Genre::fromJson(genreValue.toObject()));
    }

    return new MovieInformation(Review::fromJson(jsonObject["myReview"].toObject()),
                                jsonObject["average"].toDouble(),
                                TypeProgram::fromString(jsonObject["mediaType"].toString()),
                                jsonObject["title"].toString(),
                                jsonObject["id"].toString(),
                                jsonObject["backdropUrl"].toString(),
                                jsonObject["posterUrl"].toString(),
                                jsonObject["overview"].toString(),
                                jsonObject["release"].toString(),
                                genres

    );
}

QList<Genre *> MovieInformation::genres() const
{
    return _genres;
}

void MovieInformation::setGenres(const QList<Genre *> &newGenres)
{
    _genres = newGenres;
}

TypeProgramEnum MovieInformation::tpProgram() const
{
    return _tpProgram;
}

void MovieInformation::setTpProgram(TypeProgramEnum newTpProgram)
{
    _tpProgram = newTpProgram;
}

Review *MovieInformation::myReview() const
{
    return _myReview;
}

void MovieInformation::setMyReview(Review *newMyReview)
{
    if (_myReview == newMyReview)
        return;
    _myReview = newMyReview;
    emit myReviewChanged();
}
