#include "moviecontrol.h"

#include <core/controller/multicontroller.h>
#include <core/helper/taskrunhelper.h>

#include <core/manager/applicationmanager.h>
#include <core/model/config/configs.h>
#include <core/model/config/programconfig.h>
#include <core/model/entities/genre.h>
#include <core/model/entities/movieinformation.h>
#include <core/network/request/multidetailsrequest.h>

#include "mapper/moviemapper.h"

MovieControl::MovieControl()
    : _movie{nullptr}
    , _isLoading{true}
    , _isCanceled{false}
    , _multiController{}
{}

MovieControl::~MovieControl()
{
    delete _movie;
}

void MovieControl::onFetchEnded(MovieInformation *movieInformation)
{
    if (!movieInformation) {
        return;
    }

    if (_isCanceled) {
        delete movieInformation;
        emit finished();
        return;
    }

    setMovie(MovieMapper::toModel(movieInformation));

    setIsLoading(false);

    delete movieInformation;
}

void MovieControl::doStart(const int id, TypeProgramEnum tpProgram)
{
    setIsLoading(true);

    MultiDetailsRequest request;
    request.setTpProgram(TypeProgram::toString(tpProgram));
    request.setDsLanguage(ApplicationManager::instance().languageManager().dsLocaleBCP47());

    _multiController.findById(id, request).then([&](MovieInformation *movieInformation) {
        onFetchEnded(movieInformation);
    });
}

void MovieControl::doCancel()
{
    if (_isLoading) {
        _multiController.cancel();
        _isCanceled = true;
        return;
    }

    emit finished();
}

MovieModel *MovieControl::movie() const
{
    return _movie;
}

void MovieControl::setMovie(MovieModel *newMovie)
{
    if (_movie == newMovie) {
        return;
    }

    _movie = newMovie;
    emit movieChanged();
}

bool MovieControl::isLoading() const
{
    return _isLoading;
}

void MovieControl::setIsLoading(bool newIsLoading)
{
    if (_isLoading == newIsLoading) {
        return;
    }

    _isLoading = newIsLoading;
    emit isLoadingChanged();
}
