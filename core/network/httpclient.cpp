#include "httpclient.h"

#include <QEventLoop>
#include <QFuture>
#include <QNetworkAccessManager>
#include <QNetworkDiskCache>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QStandardPaths>
#include <QTimer>

#include "httpstatuscode.h"

HttpClient::HttpClient()
    : _networkManager{new QNetworkAccessManager()}
{
    QNetworkDiskCache* diskCache = new QNetworkDiskCache(this);
    QString cacheDir = QStandardPaths::writableLocation(QStandardPaths::CacheLocation);
    diskCache->setCacheDirectory(cacheDir);
    diskCache->setMaximumCacheSize(50 * 1024 * 1024);

    _networkManager->setCache(diskCache);
}

HttpClient::~HttpClient() = default;

Response* HttpClient::get(const QUrl& dsUrl,
                          const HeaderMap& headers,
                          const bool isUseCache,
                          const int timeout)
{
    QNetworkRequest request = QNetworkRequest(dsUrl);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute,
                         isUseCache ? QNetworkRequest::PreferCache : QNetworkRequest::AlwaysNetwork);

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
    QNetworkReply* reply = method(*_networkManager.get());

    QTimer timer;
    QEventLoop loop;

    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);

    QObject::connect(this,
                     &HttpClient::cancelRequested,
                     reply,
                     &QNetworkReply::abort,
                     Qt::QueuedConnection);

    timer.start(timeout);
    loop.exec();

    QObject::disconnect(this, nullptr, reply, nullptr);

    if (!timer.isActive()) {
        reply->abort();
        delete reply;
        return new Response(HttpStatusCode::TIMEOUT, {});
    }

    if (reply->error() == QNetworkReply::OperationCanceledError) {
        delete reply;
        return nullptr;
    }

    const QByteArray result = reply->readAll();

    const QVariant dsCacheControl = reply->rawHeader("Cache-Control");
    const QVariant dsEtag = reply->rawHeader("ETag");
    const bool isFromCache = reply->attribute(QNetworkRequest::SourceIsFromCacheAttribute).toBool();

    qInfo() << "HttpClient::makeRequest [DS_CACHE_CONTROL]" << dsCacheControl << "[DS_ETAG]"
            << dsEtag << "[IS_FROM_CACHE]" << isFromCache;

    const auto status = HttpStatusCode(
        reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());

    delete reply;

    return new Response(status, QJsonDocument::fromJson(result));
}

// TODO Review to reduce duplicate code.
QFuture<Response*> HttpClient::getAsync(const QUrl& dsUrl,
                                        const HeaderMap& headers,
                                        QNetworkRequest::CacheLoadControl typeCacheControl,
                                        const int timeout)
{
    QPromise<Response*> promise;
    auto future = promise.future();

    QNetworkRequest request = QNetworkRequest(dsUrl);
    request.setSslConfiguration(QSslConfiguration::defaultConfiguration());
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, typeCacheControl);

    setRawHeaders(&request, headers);

    QNetworkReply* reply = _networkManager->get(request);

    QTimer timer;

    QObject::connect(&timer, &QTimer::timeout, reply, &QNetworkReply::abort, Qt::QueuedConnection);

    QObject::connect(this,
                     &HttpClient::cancelRequested,
                     reply,
                     &QNetworkReply::abort,
                     Qt::QueuedConnection);

    QObject::connect(reply, &QNetworkReply::finished, [reply, promise = std::move(promise)]() mutable {
        if (reply->error() != QNetworkReply::NoError) {
            promise.addResult(nullptr);
            promise.finish();

            reply->deleteLater();
            return;
        }

        const auto status = HttpStatusCode(
            reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt());

        const QVariant dsCacheControl = reply->rawHeader("Cache-Control");
        const QVariant dsEtag = reply->rawHeader("ETag");
        const bool isFromCache = reply->attribute(QNetworkRequest::SourceIsFromCacheAttribute)
                                     .toBool();

        qInfo() << "HttpClient::getAsync [DS_CACHE_CONTROL]" << dsCacheControl << "[DS_ETAG]"
                << dsEtag << "[IS_FROM_CACHE]" << isFromCache;

        Response* response = new Response(status, QJsonDocument::fromJson(reply->readAll()));
        promise.addResult(response);
        promise.finish();

        reply->deleteLater();
    });

    return future;
}

void HttpClient::cancel()
{
    emit cancelRequested();
}
