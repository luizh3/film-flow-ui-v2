#include "reviewmodel.h"

ReviewModel::ReviewModel()
    : _author{nullptr}
    , _score{0.00}
    , _likesCount{0}
    , _tpProgram{TypeProgramEnum::UNKNOW}
    , _isLikedByMe{false}
    , _reviewId{QStringLiteral("")}
    , _title{QStringLiteral("")}
    , _description{QStringLiteral("")}
    , _movieId{QStringLiteral("")}
    , _programTitle(QStringLiteral(""))
{}

ReviewModel::ReviewModel(double score,
                         int likesCount,
                         TypeProgramEnum tpProgram,
                         bool isLikedByMe,
                         QString reviewId,
                         QString title,
                         QString description,
                         QString movieId,
                         QString programTitle,
                         UserModel *author)
    : _author{author}
    , _score(score)
    , _likesCount(likesCount)
    , _tpProgram(tpProgram)
    , _isLikedByMe(isLikedByMe)
    , _reviewId(std::move(reviewId))
    , _title(std::move(title))
    , _description(std::move(description))
    , _movieId(std::move(movieId))
    , _programTitle(std::move(programTitle))
{}

double ReviewModel::score() const
{
    return _score;
}

void ReviewModel::setScore(double newScore)
{
    if (qFuzzyCompare(_score, newScore)) {
        return;
    }

    _score = newScore;
    emit scoreChanged();
}

int ReviewModel::likesCount() const
{
    return _likesCount;
}

void ReviewModel::setLikesCount(int newLikesCount)
{
    if (_likesCount == newLikesCount) {
        return;
    }

    _likesCount = newLikesCount;
    emit likesCountChanged();
}

TypeProgramEnum ReviewModel::tpProgram() const
{
    return _tpProgram;
}

void ReviewModel::setTpProgram(TypeProgramEnum newTpProgram)
{
    if (_tpProgram == newTpProgram) {
        return;
    }

    _tpProgram = newTpProgram;
    emit tpProgramChanged();
}

bool ReviewModel::isLikedByMe() const
{
    return _isLikedByMe;
}

void ReviewModel::setIsLikedByMe(bool newIsLikedByMe)
{
    if (_isLikedByMe == newIsLikedByMe) {
        return;
    }

    _isLikedByMe = newIsLikedByMe;
    emit isLikedByMeChanged();
}

QString ReviewModel::reviewId() const
{
    return _reviewId;
}

void ReviewModel::setReviewId(const QString &newReviewId)
{
    if (_reviewId == newReviewId) {
        return;
    }

    _reviewId = newReviewId;
    emit reviewIdChanged();
}

QString ReviewModel::title() const
{
    return _title;
}

void ReviewModel::setTitle(const QString &newTitle)
{
    if (_title == newTitle) {
        return;
    }

    _title = newTitle;
    emit titleChanged();
}

QString ReviewModel::description() const
{
    return _description;
}

void ReviewModel::setDescription(const QString &newDescription)
{
    if (_description == newDescription) {
        return;
    }

    _description = newDescription;
    emit descriptionChanged();
}

QString ReviewModel::movieId() const
{
    return _movieId;
}

void ReviewModel::setMovieId(const QString &newMovieId)
{
    if (_movieId == newMovieId) {
        return;
    }

    _movieId = newMovieId;
    emit movieIdChanged();
}

QString ReviewModel::programTitle() const
{
    return _programTitle;
}

void ReviewModel::setProgramTitle(const QString &newProgramTitle)
{
    if (_programTitle == newProgramTitle) {
        return;
    }

    _programTitle = newProgramTitle;
    emit programTitleChanged();
}

UserModel *ReviewModel::author() const
{
    return _author;
}

void ReviewModel::setAuthor(UserModel *newAuthor)
{
    if (_author == newAuthor) {
        return;
    }

    _author = newAuthor;
    emit authorChanged();
}
