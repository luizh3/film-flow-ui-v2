#include "movieslidercontrol.h"

#include <core/entities/searchmovies.h>
#include <core/network/request/sectionrequest.h>
#include <core/helper/taskrunhelper.h>
#include <core/controller/sectioncontroller.h>
#include <core/entities/movieinformation.h>

#include <core/entities/signup.h>

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

    QFutureWatcher<SearchMovies*>* future = TaskRunHelper::async<SearchMovies*>(
        [&]() {

            SectionRequest request;
            request.setKey("TOP_RATED");
            request.setPage( 1 );
            request.setTpProgram( TypeProgramEnum::MOVIE );

            return SectionController().find( request );
        });

    QObject::connect( future, &QFutureWatcher<SearchMovies*>::finished, this, [this, future]() {

        if ( future->isFinished() && !future->isCanceled() ) {

            std::unique_ptr<SearchMovies> searchMovies( future->result() );

            _movies = searchMovies->movies();

            searchMovies->setMovies({});

            emit movieChanged( QVariant::fromValue( _movies.last() ) );

        }

        future->deleteLater();
    } );

}
