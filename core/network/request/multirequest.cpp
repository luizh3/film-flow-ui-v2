#include "multirequest.h"

#include <QUrlQuery>

MultiRequest::MultiRequest()
    : _dsQuery{QStringLiteral("")}
    , _dsLanguage{QStringLiteral("")}
    , _page{0}
{}

QString MultiRequest::dsQuery() const
{
    return _dsQuery;
}

void MultiRequest::setDsQuery(const QString &newDsQuery)
{
    _dsQuery = newDsQuery;
}

int MultiRequest::page() const
{
    return _page;
}

void MultiRequest::setPage(int newPage)
{
    _page = newPage;
}

QString MultiRequest::dsLanguage() const
{
    return _dsLanguage;
}

void MultiRequest::setDsLanguage(const QString &newDsLanguage)
{
    _dsLanguage = newDsLanguage;
}

QUrlQuery MultiRequest::toQuerys() const
{
    QUrlQuery query;

    query.addQueryItem(QStringLiteral("page"), QString::number(_page));
    query.addQueryItem(QStringLiteral("query"), _dsQuery);
    query.addQueryItem(QStringLiteral("language"), _dsLanguage);

    return query;
}
