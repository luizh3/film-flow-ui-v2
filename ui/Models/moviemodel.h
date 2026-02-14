#ifndef MOVIEMODEL_H
#define MOVIEMODEL_H

#include <QObject>

#include <models_global.h>

#include "genremodel.h"
#include "reviewmodel.h"

class MODELS_EXPORT MovieModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ReviewModel *myReview READ myReview WRITE setMyReview NOTIFY myReviewChanged FINAL)
    Q_PROPERTY(double average READ average WRITE setAverage NOTIFY averageChanged FINAL)
    Q_PROPERTY(
        TypeProgramEnum tpProgram READ tpProgram WRITE setTpProgram NOTIFY tpProgramChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(QString id READ id WRITE setId NOTIFY idChanged FINAL)
    Q_PROPERTY(
        QString backdropUrl READ backdropUrl WRITE setBackdropUrl NOTIFY backdropUrlChanged FINAL)
    Q_PROPERTY(QString posterUrl READ posterUrl WRITE setPosterUrl NOTIFY posterUrlChanged FINAL)
    Q_PROPERTY(QString overview READ overview WRITE setOverview NOTIFY overviewChanged FINAL)
    Q_PROPERTY(QString release READ release WRITE setRelease NOTIFY releaseChanged FINAL)
    Q_PROPERTY(QList<GenreModel *> genres READ genres WRITE setGenres NOTIFY genresChanged FINAL)
public:
    MovieModel();
    MovieModel(ReviewModel *myReview,
               double average,
               TypeProgramEnum tpProgram,
               const QString &title,
               const QString &id,
               const QString &backdropUrl,
               const QString &posterUrl,
               const QString &overview,
               const QString &release,
               const QList<GenreModel *> &genres);

    ~MovieModel();

    ReviewModel *myReview() const;
    void setMyReview(ReviewModel *newMyReview);

    double average() const;
    void setAverage(double newAverage);

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

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

    QList<GenreModel *> genres() const;
    void setGenres(const QList<GenreModel *> &newGenres);

signals:
    void myReviewChanged();

    void averageChanged();

    void tpProgramChanged();

    void titleChanged();

    void idChanged();

    void backdropUrlChanged();

    void posterUrlChanged();

    void overviewChanged();

    void releaseChanged();

    void genresChanged();

private:
    ReviewModel *_myReview;
    double _average;
    TypeProgramEnum _tpProgram;
    QString _title;
    QString _id;
    QString _backdropUrl;
    QString _posterUrl;
    QString _overview;
    QString _release;
    QList<GenreModel *> _genres;
};

#endif // MOVIEMODEL_H
