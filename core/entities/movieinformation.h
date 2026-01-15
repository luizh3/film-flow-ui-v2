#ifndef MOVIEINFORMATION_H
#define MOVIEINFORMATION_H

#include <QObject>
#include <QQmlEngine>

#include <core_global.h>

#include "typeprogramenum.h"

#include "review.h"

class QJsonDocument;
class QJsonObject;
class Genre;
class CORE_EXPORT MovieInformation : public QObject {
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString id READ id CONSTANT)
    Q_PROPERTY( QString title READ title CONSTANT )
    Q_PROPERTY(QString backdropUrl READ backdropUrl CONSTANT);
    Q_PROPERTY(QString posterUrl READ posterUrl CONSTANT)
    Q_PROPERTY(double average READ average CONSTANT)
    Q_PROPERTY(QString overview READ overview CONSTANT)
    Q_PROPERTY(QString release READ release CONSTANT)
    Q_PROPERTY(QList<Genre *> genres READ genres CONSTANT)
    Q_PROPERTY(Review *myReview READ myReview CONSTANT)
    Q_PROPERTY(TypeProgram::TypeProgramEnum programType READ tpProgram CONSTANT)
public:
    MovieInformation();

    explicit MovieInformation(Review *myReview,
                              double average,
                              const TypeProgramEnum tpProgram,
                              const QString &title,
                              const QString &id,
                              const QString &backdropUrl,
                              const QString &posterUrl,
                              const QString &overview,
                              const QString &release,
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

    QString release() const;
    void setRelease(const QString &newRelease);

    static MovieInformation *fromJson(const QJsonDocument &jsonDocument);
    static MovieInformation *fromJson(const QJsonObject &jsonObject);

    QList<Genre *> genres() const;
    void setGenres(const QList<Genre *> &newGenres);

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

    Review *myReview() const;
    void setMyReview(Review *newMyReview);

signals:
    void myReviewChanged();

private:
    Review *_myReview;
    double _average;
    TypeProgramEnum _tpProgram;
    QString _title;
    QString _id;
    QString _backdropUrl;
    QString _posterUrl;
    QString _overview;
    QString _release;
    QList<Genre *> _genres;
};

#endif // MOVIEINFORMATION_H
