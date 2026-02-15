#include "movieslidercontrol.h"

#include <core/controller/sectioncontroller.h>
#include <core/helper/taskrunhelper.h>
#include <core/model/result/searchmoviesresult.h>
#include <core/network/request/sectionrequest.h>

#include <core/network/request/signup.h>

#include "mapper/moviemapper.h"

MovieSliderControl::MovieSliderControl()
    : _sectionController{new SectionController()}
    , _movies{{}}
    , _currentIndex{0}
{}

MovieSliderControl::~MovieSliderControl()
{
    delete _sectionController;
    qDeleteAll(_movies);
}

void MovieSliderControl::doStart() {

    fetchMovies();

}

void MovieSliderControl::next()
{

    if( _currentIndex >= _movies.length() - 1 ){
        _currentIndex = 0;
        emit movieChanged( QVariant::fromValue( _movies.at(_currentIndex ) ) );
        return;
    }

    _currentIndex++;

    emit movieChanged( QVariant::fromValue( _movies.at(_currentIndex ) ) );

}

void MovieSliderControl::previous()
{

    if( _currentIndex == 0 ) {
        _currentIndex = _movies.length() - 1;
        emit movieChanged( QVariant::fromValue( _movies.at(_currentIndex ) ) );
        return;
    }

    _currentIndex--;
    emit movieChanged( QVariant::fromValue( _movies.at(_currentIndex ) ) );

}

void MovieSliderControl::fetchMovies() {
    SectionRequest request;
    request.setKey("TOP_RATED");
    request.setPage(1);
    request.setTpProgram(TypeProgramEnum::MOVIE);

    _sectionController->find(request).then([&](SearchMoviesResult* searchMovies) {
        if (!searchMovies) {
            return;
        }

        _movies = MovieMapper::toModels(searchMovies->movies());

        emit movieChanged(QVariant::fromValue(_movies.last()));

        delete searchMovies;
    });
}
