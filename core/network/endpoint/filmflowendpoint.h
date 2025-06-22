#ifndef FILMFLOWENDPOINT_H
#define FILMFLOWENDPOINT_H

#include <QMap>
#include <QString>

class QUrl;
class FilmFlowEndpoint {
public:
    FilmFlowEndpoint();

protected:
    QString _host;
    QString _token;
    QMap<QString, QString> _headers;

    QUrl toEndpoint( const QString& path ) const;
};

#endif // FILMFLOWENDPOINT_H
