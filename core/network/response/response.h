#ifndef RESPONSE_H
#define RESPONSE_H

#include <QJsonDocument>

#include <network/httpstatuscode.h>

class Response {
public:
    Response( const HttpStatusCode status, const QJsonDocument data );

    HttpStatusCode status() const;
    void setStatus(HttpStatusCode newStatus);

    QJsonDocument data() const;
    void setData(const QJsonDocument &newData);

    bool isStatusValid() const;

private:
    HttpStatusCode _status;
    QJsonDocument _data;
};

#endif // RESPONSE_H
