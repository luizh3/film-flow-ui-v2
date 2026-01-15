#include "multidetailsrequest.h"

#include <QUrlQuery>

MultiDetailsRequest::MultiDetailsRequest()
    : _tpProgram{QStringLiteral("")}
    , _dsLanguage(QStringLiteral(""))
{}

QUrlQuery MultiDetailsRequest::toQuerys() const
{
    QUrlQuery query;

    query.addQueryItem(QStringLiteral("mediaType"), _tpProgram);
    query.addQueryItem(QStringLiteral("language"), _dsLanguage);

    return std::move(query);
}

QString MultiDetailsRequest::tpProgram() const
{
    return _tpProgram;
}

void MultiDetailsRequest::setTpProgram(const QString &newTpProgram)
{
    _tpProgram = newTpProgram;
}

QString MultiDetailsRequest::dsLanguage() const
{
    return _dsLanguage;
}

void MultiDetailsRequest::setDsLanguage(const QString &newDsLanguage)
{
    _dsLanguage = newDsLanguage;
}
