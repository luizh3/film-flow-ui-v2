#ifndef REVIEW_H
#define REVIEW_H

#include <QJsonDocument>

#include <core_global.h>

#include <model/enum/typeprogramenum.h>

class User;
class CORE_EXPORT Review
{

public:
    Review();

    Review(double score,
           int likesCount,
           TypeProgramEnum tpProgram,
           bool isLikedByMe,
           QString reviewId,
           QString title,
           QString description,
           QString movieId,
           QString programTitle,
           User *author = nullptr);

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

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

    int likesCount() const;
    void setLikesCount(int newLikesCount);

    bool isLikedByMe() const;
    void setIsLikedByMe(bool newIsLikedByMe);

    User *author() const;
    void setAuthor(User *newAuthor);

private:
    User *_author;
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

#endif // REVIEW_H
