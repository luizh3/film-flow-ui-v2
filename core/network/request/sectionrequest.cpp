#include "sectionrequest.h"

#include <QUrlQuery>

SectionRequest::SectionRequest() :
    _page{0},
    _tpProgram{TypeProgramEnum::UNKNOW},
    _key{QStringLiteral("")},
    _language{QStringLiteral("")}
{}

int SectionRequest::page() const
{
    return _page;
}

void SectionRequest::setPage(int newPage)
{
    _page = newPage;
}

TypeProgramEnum SectionRequest::tpProgram() const
{
    return _tpProgram;
}

void SectionRequest::setTpProgram(TypeProgramEnum newTpProgram)
{
    _tpProgram = newTpProgram;
}

QString SectionRequest::key() const
{
    return _key;
}

void SectionRequest::setKey(const QString &newKey)
{
    _key = newKey;
}

QString SectionRequest::language() const
{
    return _language;
}

void SectionRequest::setLanguage(const QString &newLanguage)
{
    _language = newLanguage;
}

QUrlQuery SectionRequest::toQuerys() const {

    QUrlQuery query;

    query.addQueryItem(QStringLiteral("page"), QString::number( _page ) );
    query.addQueryItem(QStringLiteral("language"), _language );
    query.addQueryItem(QStringLiteral("key"), _key );
    query.addQueryItem(QStringLiteral("mediaType"), TypeProgram::toString(_tpProgram));

    return query;
}
