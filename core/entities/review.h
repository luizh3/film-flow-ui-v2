#ifndef REVIEW_H
#define REVIEW_H

#include <QObject>
#include <QQmlEngine>

#include <core_global.h>

#include "typeprogramenum.h"

class CORE_EXPORT Review : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(QString reviewId READ reviewId WRITE setReviewId NOTIFY reviewIdChanged FINAL)
    Q_PROPERTY(double score READ score WRITE setScore NOTIFY scoreChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(
        QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(QString movieId READ movieId WRITE setMovieId NOTIFY movieIdChanged FINAL)
    Q_PROPERTY(QString programTitle READ programTitle WRITE setProgramTitle NOTIFY
                   programTitleChanged FINAL)
    Q_PROPERTY(TypeProgram::TypeProgramEnum programType READ tpProgram WRITE setTpProgram NOTIFY
                   tpProgramChanged FINAL)
    Q_PROPERTY(int likesCount READ likesCount WRITE setLikesCount NOTIFY likesCountChanged FINAL)
    Q_PROPERTY(bool isLikedByMe READ isLikedByMe WRITE setIsLikedByMe NOTIFY isLikedByMeChanged FINAL)

public:
    Review();

    double score() const;
    void setScore(double newScore);

    QString title() const;
    void setTitle(const QString &newTitle);

    QString description() const;
    void setDescription(const QString &newDescription);

    QString movieId() const;
    void setMovieId(const QString &newMovieId);

    QJsonDocument toJson() const;

    static Review *fromJson(const QJsonDocument &jsonDocument);
    static Review *fromJson(const QJsonObject &jsonObject);

    QString reviewId() const;
    void setReviewId(QString newReviewId);

    QString programTitle() const;
    void setProgramTitle(const QString &newProgramTitle);

    TypeProgram::TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgram::TypeProgramEnum newTpProgram);

    int likesCount() const;
    void setLikesCount(int newLikesCount);

    bool isLikedByMe() const;
    void setIsLikedByMe(bool newIsLikedByMe);

signals:
    void scoreChanged();
    void titleChanged();
    void descriptionChanged();
    void movieIdChanged();
    void reviewIdChanged();
    void programTitleChanged();
    void tpProgramChanged();
    void likesCountChanged();
    void isLikedByMeChanged();

private:
    double _score;
    int _likesCount;
    TypeProgram::TypeProgramEnum _tpProgram;
    bool _isLikedByMe;
    QString _reviewId;
    QString _title;
    QString _description;
    QString _movieId;
    QString _programTitle;
};

#endif // REVIEW_H
