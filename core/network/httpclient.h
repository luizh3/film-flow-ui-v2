#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <QByteArray>
#include <QJsonDocument>
#include <QMap>

#include "response/response.h"

using HeaderMap = QMap<QString, QString>;

class QNetworkReply;
class QNetworkRequest;
class QNetworkAccessManager;
class HttpClient
{
public:
    Response* get(const QUrl& dsUrl, const HeaderMap& headers = {}, const int timeout = 15000);

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

    void cancel();

private:
    QNetworkReply* _reply = nullptr;
};

#endif // HTTPCLIENT_H
