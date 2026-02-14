#include "paginationresult.h"

#include <QJsonObject>

PaginationResult::PaginationResult()
    : _page{0}
    , _totalPage{0}
    , _totalResult{0}
{}

PaginationResult::PaginationResult(const int page, const int totalPage, const int totalResults)
    : _page{page}
    , _totalPage{totalPage}
    , _totalResult{totalResults}
{}

PaginationResult *PaginationResult::fromJson(const QJsonObject &jsonObject)
{
    return new PaginationResult(jsonObject["page"].toInt(),
                                jsonObject["totalPage"].toInt(),
                                jsonObject["totalResults"].toInt());
}

int PaginationResult::page() const
{
    return _page;
}

void PaginationResult::setPage(int newPage)
{
    _page = newPage;
}

int PaginationResult::totalPage() const
{
    return _totalPage;
}

void PaginationResult::setTotalPage(int newTotalPage)
{
    _totalPage = newTotalPage;
}

int PaginationResult::totalResult() const
{
    return _totalResult;
}

void PaginationResult::setTotalResult(int newTotalResult)
{
    _totalResult = newTotalResult;
}
