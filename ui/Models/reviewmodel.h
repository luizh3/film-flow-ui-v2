#ifndef REVIEWMODEL_H
#define REVIEWMODEL_H

#include <QObject>
#include <QQmlEngine>

#include <core/model/enum/typeprogramenum.h>

#include <models_global.h>

#include "usermodel.h"

class MODELS_EXPORT ReviewModel : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(double score READ score WRITE setScore NOTIFY scoreChanged FINAL)
    Q_PROPERTY(int likesCount READ likesCount WRITE setLikesCount NOTIFY likesCountChanged FINAL)
    Q_PROPERTY(
        TypeProgramEnum programType READ tpProgram WRITE setTpProgram NOTIFY tpProgramChanged FINAL)
    Q_PROPERTY(bool isLikedByMe READ isLikedByMe WRITE setIsLikedByMe NOTIFY isLikedByMeChanged FINAL)
    Q_PROPERTY(QString reviewId READ reviewId WRITE setReviewId NOTIFY reviewIdChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(
        QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
    Q_PROPERTY(QString movieId READ movieId WRITE setMovieId NOTIFY movieIdChanged FINAL)
    Q_PROPERTY(QString programTitle READ programTitle WRITE setProgramTitle NOTIFY
                   programTitleChanged FINAL)
    Q_PROPERTY(UserModel *author READ author WRITE setAuthor NOTIFY authorChanged FINAL)
public:
    ReviewModel();

    ReviewModel(double score,
                int likesCount,
                TypeProgramEnum tpProgram,
                bool isLikedByMe,
                QString reviewId,
                QString title,
                QString description,
                QString movieId,
                QString programTitle,
                UserModel *_author = nullptr);

    double score() const;
    void setScore(double newScore);

    int likesCount() const;
    void setLikesCount(int newLikesCount);

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

    bool isLikedByMe() const;
    void setIsLikedByMe(bool newIsLikedByMe);

    QString reviewId() const;
    void setReviewId(const QString &newReviewId);

    QString title() const;
    void setTitle(const QString &newTitle);

    QString description() const;
    void setDescription(const QString &newDescription);

    QString movieId() const;
    void setMovieId(const QString &newMovieId);

    QString programTitle() const;
    void setProgramTitle(const QString &newProgramTitle);

    UserModel *author() const;
    void setAuthor(UserModel *newAuthor);

signals:
    void scoreChanged();
    void likesCountChanged();
    void tpProgramChanged();
    void isLikedByMeChanged();
    void reviewIdChanged();
    void titleChanged();
    void descriptionChanged();
    void movieIdChanged();
    void programTitleChanged();

    void authorChanged();

private:
    UserModel *_author;
    double _score;
    int _likesCount;
    TypeProgramEnum _tpProgram;
    bool _isLikedByMe;
    QString _reviewId;
    QString _title;
    QString _description;
    QString _movieId;
    QString _programTitle;
};

#endif // REVIEWMODEL_H
