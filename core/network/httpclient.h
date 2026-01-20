#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

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
signals:
    void cancelRequested();
};

#endif // HTTPCLIENT_H
