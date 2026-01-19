#include "httpclient.h"

#include <QEventLoop>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>

#include "httpstatuscode.h"

Response* HttpClient::get( const QUrl& dsUrl, const HeaderMap& headers, const int timeout ) {
    QNetworkRequest request = QNetworkRequest(dsUrl);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    setRawHeaders(&request, headers);

    return makeRequest(dsUrl, timeout, [&request](QNetworkAccessManager& network) {
        return network.get( request );
    });
}

Response* HttpClient::post(const QUrl& dsUrl,
                           const QJsonDocument& data,
                           const HeaderMap& headers,
                           const int timeout)
{
    QNetworkRequest request = QNetworkRequest(dsUrl);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());

    if (!data.isEmpty()) {
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    }

    setRawHeaders(&request, headers);

    return makeRequest(dsUrl, timeout, [&request, &data](QNetworkAccessManager& network) {
        return network.post(request, data.toJson());
    });
}

Response* HttpClient::put(const QUrl& dsUrl,
                          const QJsonDocument& data,
                          const HeaderMap& headers,
                          const int timeout)
{
    QNetworkRequest request = QNetworkRequest(dsUrl);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    setRawHeaders(&request, headers);

    return makeRequest(dsUrl, timeout, [&request, &data](QNetworkAccessManager& network) {
        return network.put(request, data.toJson());
    });
}

Response* HttpClient::deleteResource(const QUrl& dsUrl, const HeaderMap& headers, const int timeout)
{
    QNetworkRequest request = QNetworkRequest(dsUrl);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());

    setRawHeaders(&request, headers);

    return makeRequest(dsUrl, timeout, [&request](QNetworkAccessManager& network) {
        return network.deleteResource(request);
    });
}

void HttpClient::setRawHeaders( QNetworkRequest* request, const QMap<QString, QString>& headers ) {
    for ( auto iterator = headers.constBegin(); iterator != headers.constEnd(); ++iterator ) {
        request->setRawHeader( iterator.key().toUtf8(), iterator.value().toUtf8() );
    }
}

Response* HttpClient::makeRequest(const QUrl& dsUrl,
                                  const int timeout,
                                  std::function<QNetworkReply*(QNetworkAccessManager&)> method)
{
    QNetworkAccessManager networkManager;
    _reply = method(networkManager);

    QTimer timer;
    QEventLoop loop;

    QObject::connect( &timer, &QTimer::timeout, &loop, &QEventLoop::quit );
    QObject::connect(_reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    timer.start( timeout );
    loop.exec();

    if( !timer.isActive() ) {
        QObject::disconnect(_reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

        _reply->abort();

        _reply = nullptr;

        return new Response( HttpStatusCode::TIMEOUT, {} );
    }

    timer.stop();

    const QByteArray result = _reply->readAll();

    const HttpStatusCode status = HttpStatusCode(
        _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());

    _reply = nullptr;

    return new Response( status, QJsonDocument::fromJson( result ) );
}

void HttpClient::cancel()
{
    if (!_reply) {
        return;
    }

    if (!_reply->isRunning()) {
        return;
    }

    _reply->abort();
}
