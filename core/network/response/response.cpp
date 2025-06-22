#include "response.h"

Response::Response( const HttpStatusCode status, const QJsonDocument data ) :
    _status( status ),
    _data( data ) {}

HttpStatusCode Response::status() const
{
    return _status;
}

void Response::setStatus(HttpStatusCode newStatus)
{
    _status = newStatus;
}

QJsonDocument Response::data() const
{
    return _data;
}

void Response::setData(const QJsonDocument &newData)
{
    _data = newData;
}

bool Response::isStatusValid() const {
    return _status == HttpStatusCode::OK;
}

