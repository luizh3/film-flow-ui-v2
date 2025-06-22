#include "httpclient.h"

#include <QTimer>
#include <QEventLoop>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include "httpstatuscode.h"

HttpClient::HttpClient() {}

Response* HttpClient::get( const QUrl& dsUrl, const HeaderMap& headers, const int timeout ) {

    QNetworkRequest request = QNetworkRequest( dsUrl );
    request.setSslConfiguration( QSslConfiguration::defaultConfiguration() );
    request.setHeader( QNetworkRequest::ContentTypeHeader, "application/json" );

    setRawHeaders( &request, headers );

    return makeRequest( dsUrl, timeout, [&request]( QNetworkAccessManager& network ) {
        return network.get( request );
    } );

}

Response* HttpClient::post( const QUrl& dsUrl, const QJsonDocument& data, const int timeout ) {

    QNetworkRequest request = QNetworkRequest( dsUrl );
    request.setSslConfiguration( QSslConfiguration::defaultConfiguration() );
    request.setHeader( QNetworkRequest::ContentTypeHeader, "application/json" );

    return makeRequest( dsUrl, timeout, [&request, &data]( QNetworkAccessManager& network ) {
        return network.post( request, data.toJson() );
    } );

}

void HttpClient::setRawHeaders( QNetworkRequest* request, const QMap<QString, QString>& headers ) {
    for ( auto iterator = headers.constBegin(); iterator != headers.constEnd(); ++iterator ) {
        request->setRawHeader( iterator.key().toUtf8(), iterator.value().toUtf8() );
    }
}

Response *HttpClient::makeRequest( const QUrl& dsUrl, const int timeout, std::function<QNetworkReply* (QNetworkAccessManager &)> method) {

    QNetworkAccessManager networkManager;
    QNetworkReply* reply = method( networkManager );

    QTimer timer;
    QEventLoop loop;

    QObject::connect( &timer, &QTimer::timeout, &loop, &QEventLoop::quit );
    QObject::connect( reply, &QNetworkReply::finished, &loop, &QEventLoop::quit );

    timer.start( timeout );
    loop.exec();

    if( !timer.isActive() ) {

        QObject::disconnect( reply, &QNetworkReply::finished, &loop, &QEventLoop::quit );

        reply->abort();

        return new Response( HttpStatusCode::TIMEOUT, {} );
    }

    timer.stop();

    const QByteArray result = reply->readAll();

    const HttpStatusCode status = HttpStatusCode( reply->attribute( QNetworkRequest::HttpStatusCodeAttribute ).toInt() );

    return new Response( status, QJsonDocument::fromJson( result ) );

}
