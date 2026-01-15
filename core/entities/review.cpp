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

double Review::score() const
{
    return _score;
}

void Review::setScore(double newScore)
{
    if (qFuzzyCompare(_score, newScore)) {
        return;
    }

    _score = newScore;
    emit scoreChanged();
}

QString Review::title() const
{
    return _title;
}

void Review::setTitle(const QString &newTitle)
{
    if (_title == newTitle) {
        return;
    }

    _title = newTitle;
    emit titleChanged();
}

QString Review::description() const
{
    return _description;
}

void Review::setDescription(const QString &newDescription)
{
    if (_description == newDescription) {
        return;
    }

    _description = newDescription;
    emit descriptionChanged();
}

QString Review::movieId() const
{
    return _movieId;
}

void Review::setMovieId(const QString &newMovieId)
{
    if (_movieId == newMovieId) {
        return;
    }

    _movieId = newMovieId;
    emit movieIdChanged();
}

QString Review::reviewId() const
{
    return _reviewId;
}

void Review::setReviewId(QString newReviewId)
{
    if (_reviewId == newReviewId) {
        return;
    }

    _reviewId = newReviewId;
    emit reviewIdChanged();
}

QString Review::programTitle() const
{
    return _programTitle;
}

void Review::setProgramTitle(const QString &newProgramTitle)
{
    if (_programTitle == newProgramTitle) {
        return;
    }

    _programTitle = newProgramTitle;
    emit programTitleChanged();
}

TypeProgram::TypeProgramEnum Review::tpProgram() const
{
    return _tpProgram;
}

void Review::setTpProgram(TypeProgram::TypeProgramEnum newTpProgram)
{
    if (_tpProgram == newTpProgram) {
        return;
    }

    _tpProgram = newTpProgram;
    emit tpProgramChanged();
}

int Review::likesCount() const
{
    return _likesCount;
}

void Review::setLikesCount(int newLikesCount)
{
    if (_likesCount == newLikesCount) {
        return;
    }

    _likesCount = newLikesCount;
    emit likesCountChanged();
}

bool Review::isLikedByMe() const
{
    return _isLikedByMe;
}

void Review::setIsLikedByMe(bool newIsLikedByMe)
{
    if (_isLikedByMe == newIsLikedByMe) {
        return;
    }

    _isLikedByMe = newIsLikedByMe;
    emit isLikedByMeChanged();
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

    return std::move(jsonDocument);
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
