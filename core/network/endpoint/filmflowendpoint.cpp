#include "filmflowendpoint.h"

#include <QtGlobal>

#include <QUrl>

#include <manager/applicationmanager.h>

#include <entities/session.h>

FilmFlowEndpoint::FilmFlowEndpoint()
    : _host{qEnvironmentVariable("FILM_FLOW_API_HOST")}
    , _token{"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9."
             "eyJpZCI6IjMyZmJhYWU5LTQ2YjQtNDBlMi1hOTUyLTkwOGMxOGI2MDc5MiIsImlhdCI6MTc2Njk2NDg0OH0."
             "t8muPDXWbmnbc1E8LmOcXXWvEVkJgOY1aDb1OYj2YJw"}
    , _headers{{{"Authorization", _token}}}
{}

QUrl FilmFlowEndpoint::toEndpoint( const QString& path ) const {
    return QUrl( _host + path );
}
