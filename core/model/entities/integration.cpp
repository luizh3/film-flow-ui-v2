#include "integration.h"

Integration::Integration( const QString& token ) :
    _token{token} {}

QString Integration::token() const {
    return _token;
}

void Integration::setToken( const QString& newToken ) {
    _token = newToken;
}
