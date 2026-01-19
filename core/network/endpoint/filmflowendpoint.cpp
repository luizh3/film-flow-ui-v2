#include "filmflowendpoint.h"

#include <QtGlobal>

#include <QUrl>

#include <manager/applicationmanager.h>

#include <entities/session.h>

// TODO this token is fake, is a token of the middleware, not dangerous commit this. The private variables, they are in the .env file.
FilmFlowEndpoint::FilmFlowEndpoint(const Session* session)
    : _host{qEnvironmentVariable("FILM_FLOW_API_HOST")}
    , _token{session->token()}
    , _headers{{{"Authorization", _token}}}
{}

QUrl FilmFlowEndpoint::toEndpoint( const QString& path ) const {
    return QUrl( _host + path );
}
