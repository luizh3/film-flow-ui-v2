#ifndef FILMFLOWENDPOINT_H
#define FILMFLOWENDPOINT_H

#include <QMap>
#include <QString>

#include <memory.h>

class QUrl;
class Session;
class HttpClient;
class FilmFlowEndpoint {
public:
    FilmFlowEndpoint(const Session* session);
    virtual ~FilmFlowEndpoint();

    void cancel() const;

protected:
    QString _host;
    QString _token;
    QMap<QString, QString> _headers;
    std::unique_ptr<HttpClient> _httpClient;

    QUrl toEndpoint(const QString& path) const;
};

#endif // FILMFLOWENDPOINT_H
