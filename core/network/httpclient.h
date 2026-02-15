#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QFuture>
#include <QJsonDocument>
#include <QMap>
#include <QObject>

#include "response/response.h"

using HeaderMap = QMap<QString, QString>;

class QNetworkReply;
class QNetworkRequest;
class QNetworkAccessManager;
class HttpClient : public QObject
{
    Q_OBJECT
public:
    HttpClient();
    ~HttpClient();

    Response* get(const QUrl& dsUrl,
                  const HeaderMap& headers = {},
                  const bool isUseCache = true,
                  const int timeout = 15000);

    Response* post(const QUrl& dsUrl,
                   const QJsonDocument& request,
                   const HeaderMap& headers = {},
                   const int timeout = 15000);

    Response* put(const QUrl& dsUrl,
                  const QJsonDocument& data,
                  const HeaderMap& headers = {},
                  const int timeout = 15000);

    Response* deleteResource(const QUrl& dsUrl,
                             const HeaderMap& headers = {},
                             const int timeout = 15000);

    void setRawHeaders(QNetworkRequest* request, const QMap<QString, QString>& values);

    Response* makeRequest(const QUrl& dsUrl,
                          const int timeout,
                          std::function<QNetworkReply*(QNetworkAccessManager& network)> method);

    QFuture<Response*> getAsync(const QUrl& dsUrl,
                                const HeaderMap& headers = {},
                                const bool isUseCache = false,
                                const int timeout = 15000);

    void cancel();
signals:
    void cancelRequested();

private:
    std::unique_ptr<QNetworkAccessManager> _networkManager;
};

#endif // HTTPCLIENT_H
