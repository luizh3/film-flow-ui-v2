#include "movieslidercontrol.h"

#include <core/controller/sectioncontroller.h>
#include <core/helper/taskrunhelper.h>
#include <core/model/result/searchmoviesresult.h>
#include <core/network/request/sectionrequest.h>

#include <core/network/request/signup.h>

#include "mapper/moviemapper.h"

MovieSliderControl::MovieSliderControl() :
    _movies{{}},
    _currentIndex{0}{}

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
    QFutureWatcher<SearchMoviesResult*>* future = TaskRunHelper::async<SearchMoviesResult*>([&]() {
        SectionRequest request;
        request.setKey("TOP_RATED");
        request.setPage(1);
        request.setTpProgram(TypeProgramEnum::MOVIE);

        return SectionController().find(request);
    });

    QObject::connect(future, &QFutureWatcher<SearchMoviesResult*>::finished, this, [this, future]() {
        if ( future->isFinished() && !future->isCanceled() ) {
            std::unique_ptr<SearchMoviesResult> searchMovies(future->result());

            _movies = MovieMapper::toModels(searchMovies->movies());

            emit movieChanged( QVariant::fromValue( _movies.last() ) );

        }

        future->deleteLater();
    });
}
