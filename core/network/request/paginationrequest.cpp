#include "paginationrequest.h"

#include <QUrlQuery>

PaginationRequest::PaginationRequest()
    : _page{0}
{}

int PaginationRequest::page() const
{
    return _page;
}

void PaginationRequest::setPage(int newPage)
{
    _page = newPage;
}

QUrlQuery PaginationRequest::toQuerys() const
{
    QUrlQuery query;

    query.addQueryItem(QStringLiteral("page"), QString::number(_page));

    return std::move(query);
}
