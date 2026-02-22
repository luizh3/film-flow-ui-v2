#include "moviemodel.h"

MovieModel::MovieModel()
    : _myReview{nullptr}
    , _average{0.00}
    , _tpProgram{PresenterTypeProgramEnum::UNKNOW}
    , _title{QStringLiteral("")}
    , _id{QStringLiteral("")}
    , _backdropUrl{QStringLiteral("")}
    , _posterUrl{QStringLiteral("")}
    , _overview{QStringLiteral("")}
    , _releaseDate{QStringLiteral("")}
    , _genres{}
{}

MovieModel::MovieModel(ReviewModel *myReview,
                       double average,
                       PresenterTypeProgramEnum tpProgram,
                       const QString &title,
                       const QString &id,
                       const QString &backdropUrl,
                       const QString &posterUrl,
                       const QString &overview,
                       const QString &releaseDate,
                       const QList<GenreModel *> &genres)
    : _myReview(myReview)
    , _average(average)
    , _tpProgram(tpProgram)
    , _title(title)
    , _id(id)
    , _backdropUrl(backdropUrl)
    , _posterUrl(posterUrl)
    , _overview(overview)
    , _releaseDate(releaseDate)
    , _genres(genres)
{}

MovieModel::~MovieModel()
{
    delete _myReview;
    qDeleteAll(_genres);
}

ReviewModel *MovieModel::myReview() const
{
    return _myReview;
}

void MovieModel::setMyReview(ReviewModel *newMyReview)
{
    if (_myReview == newMyReview) {
        return;
    }

    _myReview = newMyReview;
    emit myReviewChanged();
}

double MovieModel::average() const
{
    return _average;
}

void MovieModel::setAverage(double newAverage)
{
    if (qFuzzyCompare(_average, newAverage)) {
        return;
    }

    _average = newAverage;
    emit averageChanged();
}

PresenterTypeProgramEnum MovieModel::tpProgram() const
{
    return _tpProgram;
}

void MovieModel::setTpProgram(PresenterTypeProgramEnum newTpProgram)
{
    if (_tpProgram == newTpProgram) {
        return;
    }

    _tpProgram = newTpProgram;
    emit tpProgramChanged();
}

QString MovieModel::title() const
{
    return _title;
}

void MovieModel::setTitle(const QString &newTitle)
{
    if (_title == newTitle) {
        return;
    }

    _title = newTitle;
    emit titleChanged();
}

QString MovieModel::id() const
{
    return _id;
}

void MovieModel::setId(const QString &newId)
{
    if (_id == newId) {
        return;
    }

    _id = newId;
    emit idChanged();
}

QString MovieModel::backdropUrl() const
{
    return _backdropUrl;
}

void MovieModel::setBackdropUrl(const QString &newBackdropUrl)
{
    if (_backdropUrl == newBackdropUrl) {
        return;
    }

    _backdropUrl = newBackdropUrl;
    emit backdropUrlChanged();
}

QString MovieModel::posterUrl() const
{
    return _posterUrl;
}

void MovieModel::setPosterUrl(const QString &newPosterUrl)
{
    if (_posterUrl == newPosterUrl) {
        return;
    }

    _posterUrl = newPosterUrl;
    emit posterUrlChanged();
}

QString MovieModel::overview() const
{
    return _overview;
}

void MovieModel::setOverview(const QString &newOverview)
{
    if (_overview == newOverview) {
        return;
    }

    _overview = newOverview;
    emit overviewChanged();
}

QString MovieModel::releaseDate() const
{
    return _releaseDate;
}

void MovieModel::setReleaseDate(const QString &newReleaseDate)
{
    if (_releaseDate == newReleaseDate) {
        return;
    }

    _releaseDate = newReleaseDate;
    emit releaseDateChanged();
}

QList<GenreModel *> MovieModel::genres() const
{
    return _genres;
}

void MovieModel::setGenres(const QList<GenreModel *> &newGenres)
{
    if (_genres == newGenres) {
        return;
    }

    _genres = newGenres;
    emit genresChanged();
}
