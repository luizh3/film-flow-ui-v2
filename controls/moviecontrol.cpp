#include "moviecontrol.h"

#include <core/controller/multicontroller.h>
#include <core/helper/taskrunhelper.h>

#include <core/entities/configs.h>
#include <core/entities/genre.h>
#include <core/entities/programconfig.h>
#include <core/manager/applicationmanager.h>
#include <core/network/request/multidetailsrequest.h>

MovieControl::MovieControl()
    : _isLoading{true}
    , _isCanceled{false}
    , _movie{nullptr}
    , _multiController{}
{}

MovieControl::~MovieControl()
{
    delete _movie;
}

void MovieControl::doStart(const int id, TypeProgramEnum tpProgram)
{
    setIsLoading(true);

    MultiDetailsRequest request;
    request.setTpProgram(TypeProgram::toString(tpProgram));
    request.setDsLanguage(ApplicationManager::instance().languageManager().dsLocaleBCP47());

    MovieInformation *movieInformation = nullptr;

    TaskRunHelper::runSync([&]() { movieInformation = _multiController.findById(id, request); });

    if (_isCanceled) {
        emit finished();
        return;
    }

    setMovie(movieInformation);

    setIsLoading(false);
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

void MovieControl::doUpdateReview(Review *review)
{
    Review *oldRview = _movie->myReview();
    delete oldRview;

    _movie->setMyReview(review);
}

MovieInformation *MovieControl::movie() const
{
    return _movie;
}

void MovieControl::setMovie(MovieInformation *newMovie)
{
    if (_movie == newMovie)
        return;
    _movie = newMovie;
    emit movieChanged();
}

bool MovieControl::isLoading() const
{
    return _isLoading;
}

void MovieControl::setIsLoading(bool newIsLoading)
{
    if (_isLoading == newIsLoading)
        return;
    _isLoading = newIsLoading;
    emit isLoadingChanged();
}
