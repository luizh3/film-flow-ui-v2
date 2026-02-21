#include "movieslistcontrol.h"

#include <core/controller/sectioncontroller.h>
#include <core/model/entities/movieinformation.h>
#include <core/model/result/searchmoviesresult.h>
#include <core/network/request/sectionrequest.h>

#include "mapper/typeprogramenummapper.h"

MoviesListControl::MoviesListControl()
    : _sectionRequest{new SectionRequest()}
    , _sectionController{new SectionController()}
{
    QObject::connect(&_movieListModel,
                     &MoviesListModel::fetchMovies,
                     this,
                     &MoviesListControl::onFetchMovies);
}

MoviesListControl::~MoviesListControl()
{
    QObject::disconnect(&_movieListModel,
                        &MoviesListModel::fetchMovies,
                        this,
                        &MoviesListControl::onFetchMovies);

    _sectionController->cancel();

    _sectionController->deleteLater();

    delete _sectionRequest;
}

void MoviesListControl::onFetchMovies()
{
    _sectionRequest->setPage(_sectionRequest->page() + 1);

    _sectionController->find(*_sectionRequest).then([this](SearchMoviesResult *searchMovies) {
        onFetchEnded(searchMovies);
    });
}

void MoviesListControl::setTpProgram(PresenterTypeProgramEnum newTpProgram)
{
    if (!_sectionRequest) {
        return;
    }

    _sectionRequest->setTpProgram(TypeProgramEnumMapper::toEntity(newTpProgram));
}

void MoviesListControl::setKey(const QString &newKey)
{
    if (!_sectionRequest) {
        return;
    }

    _sectionRequest->setKey(newKey);
}

MoviesListModel *MoviesListControl::model()
{
    return &_movieListModel;
}

void MoviesListControl::onFetchEnded(SearchMoviesResult *searchMoviesResult)
{
    if (!searchMoviesResult) {
        return;
    }

    const QList<MovieInformation *> &movies = searchMoviesResult->movies();

    _movieListModel.onFetchEnded(movies.count(),
                                 [movies](MoviesListModel::CardMovie *cardMovie, const int index) {
                                     MoviesListControl::applyToCards(cardMovie, movies[index]);
                                 });

    delete searchMoviesResult;
}

void MoviesListControl::applyToCards(MoviesListModel::CardMovie *cardMovie,
                                     const MovieInformation *movieInformation)
{
    cardMovie->average = movieInformation->average();
    cardMovie->id = movieInformation->id();
    cardMovie->posterUrl = movieInformation->posterUrl();
    cardMovie->title = movieInformation->title();
    cardMovie->tpProgram = TypeProgramEnumMapper::toModel(movieInformation->tpProgram());
    cardMovie->isLoading = false;
}
