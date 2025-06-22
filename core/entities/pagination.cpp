#include "pagination.h"

#include <QJsonObject>

Pagination::Pagination() :
    _page{0},
    _totalPage{0},
    _totalResult{0}
{}

Pagination::Pagination(const int page, const int totalPage, const int totalResults)
    : _page{page}
    , _totalPage{totalPage}
    , _totalResult{totalResults}
{}

Pagination *Pagination::fromJson(const QJsonObject &jsonObject)
{
    return new Pagination(
        jsonObject["page"].toInt(),
        jsonObject["totalPage"].toInt(),
        jsonObject["totalResults"].toInt()
    );
}

int Pagination::page() const
{
    return _page;
}

void Pagination::setPage(int newPage)
{
    _page = newPage;
}

int Pagination::totalPage() const
{
    return _totalPage;
}

void Pagination::setTotalPage(int newTotalPage)
{
    _totalPage = newTotalPage;
}

int Pagination::totalResult() const
{
    return _totalResult;
}

void Pagination::setTotalResult(int newTotalResult)
{
    _totalResult = newTotalResult;
}
