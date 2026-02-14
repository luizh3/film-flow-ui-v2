#include "review.h"

#include <QJsonDocument>
#include <QJsonObject>

Review::Review()
    : _score{0.00}
    , _likesCount{0}
    , _tpProgram{TypeProgram::TypeProgramEnum::UNKNOW}
    , _isLikedByMe{false}
    , _reviewId{QStringLiteral("")}
    , _title{QStringLiteral("")}
    , _description{QStringLiteral("")}
    , _movieId{QStringLiteral("")}
    , _programTitle(QStringLiteral(""))
{}

Review::Review(double score,
               int likesCount,
               TypeProgram::TypeProgramEnum tpProgram,
               bool isLikedByMe,
               QString reviewId,
               QString title,
               QString description,
               QString movieId,
               QString programTitle)
    : _score(score)
    , _likesCount(likesCount)
    , _tpProgram(tpProgram)
    , _isLikedByMe(isLikedByMe)
    , _reviewId(std::move(reviewId))
    , _title(std::move(title))
    , _description(std::move(description))
    , _movieId(std::move(movieId))
    , _programTitle(std::move(programTitle))
{}

double Review::score() const
{
    return _score;
}

void Review::setScore(double newScore)
{
    _score = newScore;
}

QString Review::title() const
{
    return _title;
}

void Review::setTitle(const QString &newTitle)
{
    _title = newTitle;
}

QString Review::description() const
{
    return _description;
}

void Review::setDescription(const QString &newDescription)
{
    _description = newDescription;
}

QString Review::movieId() const
{
    return _movieId;
}

void Review::setMovieId(const QString &newMovieId)
{
    _movieId = newMovieId;
}

QString Review::reviewId() const
{
    return _reviewId;
}

void Review::setReviewId(QString newReviewId)
{
    _reviewId = newReviewId;
}

QString Review::programTitle() const
{
    return _programTitle;
}

void Review::setProgramTitle(const QString &newProgramTitle)
{
    _programTitle = newProgramTitle;
}

TypeProgram::TypeProgramEnum Review::tpProgram() const
{
    return _tpProgram;
}

void Review::setTpProgram(TypeProgram::TypeProgramEnum newTpProgram)
{

    _tpProgram = newTpProgram;
}

int Review::likesCount() const
{
    return _likesCount;
}

void Review::setLikesCount(int newLikesCount)
{

    _likesCount = newLikesCount;
}

bool Review::isLikedByMe() const
{
    return _isLikedByMe;
}

void Review::setIsLikedByMe(bool newIsLikedByMe)
{
    _isLikedByMe = newIsLikedByMe;
}

QJsonDocument Review::toJson() const
{
    QJsonDocument jsonDocument;

    QJsonObject jsonObject;

    jsonObject["title"] = _title;
    jsonObject["description"] = _description;
    jsonObject["score"] = _score;
    jsonObject["movieId"] = _movieId;
    jsonObject["programType"] = TypeProgram::toString(_tpProgram);
    jsonObject["programTitle"] = _programTitle;

    jsonDocument.setObject(jsonObject);

    return jsonDocument;
}

Review *Review::fromJson(const QJsonDocument &jsonDocument)
{
    return Review::fromJson(jsonDocument.object());
}

Review *Review::fromJson(const QJsonObject &jsonObject)
{
    if (jsonObject.isEmpty()) {
        return nullptr;
    }

    Review *review = new Review();

    review->setTitle(jsonObject["title"].toString());
    review->setDescription(jsonObject["description"].toString());
    review->setScore(jsonObject["score"].toDouble());
    review->setMovieId(jsonObject["movieId"].toString());
    review->setReviewId(jsonObject["reviewId"].toString());
    review->setTpProgram(TypeProgram::fromString(jsonObject["programType"].toString()));
    review->setProgramTitle(jsonObject["programTitle"].toString());
    review->setLikesCount(jsonObject["likesCount"].toInt());
    review->setIsLikedByMe(jsonObject["likedByMe"].toBool());

    return review;
}
