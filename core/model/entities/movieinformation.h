#ifndef MOVIEINFORMATION_H
#define MOVIEINFORMATION_H

#include <core_global.h>

#include <model/enum/typeprogramenum.h>

#include <model/entities/review.h>

class QJsonDocument;
class QJsonObject;
class Genre;
class CORE_EXPORT MovieInformation
{
public:
    MovieInformation();
    ~MovieInformation();

    explicit MovieInformation(Review *myReview,
                              double average,
                              const TypeProgramEnum tpProgram,
                              const QString &title,
                              const QString &id,
                              const QString &backdropUrl,
                              const QString &posterUrl,
                              const QString &overview,
                              const QDate &releaseDate,
                              const QList<Genre *> &genres);

    double average() const;
    void setAverage(double newAverage);

    QString title() const;
    void setTitle(const QString &newTitle);

    QString id() const;
    void setId(const QString &newId);

    QString backdropUrl() const;
    void setBackdropUrl(const QString &newBackdropUrl);

    QString posterUrl() const;
    void setPosterUrl(const QString &newPosterUrl);

    QString overview() const;
    void setOverview(const QString &newOverview);

    QDate releaseDate() const;
    void setReleaseDate(const QDate &newReleaseDate);

    static MovieInformation *fromJson(const QJsonDocument &jsonDocument);
    static MovieInformation *fromJson(const QJsonObject &jsonObject);

    QList<Genre *> genres() const;
    void setGenres(const QList<Genre *> &newGenres);

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

    Review *myReview() const;
    void setMyReview(Review *newMyReview);

private:
    Review *_myReview;
    double _average;
    TypeProgramEnum _tpProgram;
    QString _title;
    QString _id;
    QString _backdropUrl;
    QString _posterUrl;
    QString _overview;
    QDate _releaseDate;
    QList<Genre *> _genres;
};

#endif // MOVIEINFORMATION_H
