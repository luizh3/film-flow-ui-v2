#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QMap>
#include <QByteArray>
#include <QJsonDocument>

#include "response/response.h"

using HeaderMap = QMap<QString, QString>;

class QNetworkReply;
class QNetworkRequest;
class QNetworkAccessManager;
class HttpClient : public QObject {
    Q_OBJECT
public:
    HttpClient();

    static Response* get( const QUrl& dsUrl, const HeaderMap& headers = {}, const int timeout = 15000 );
    static Response* post( const QUrl& dsUrl, const QJsonDocument& request, const int timeout = 15000 );

    static void setRawHeaders( QNetworkRequest* request, const QMap<QString,QString>& values );

    static Response* makeRequest(const QUrl& dsUrl, const int timeout, std::function<QNetworkReply*(QNetworkAccessManager& network)> method);
};

#endif // HTTPCLIENT_H
