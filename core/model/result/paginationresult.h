#ifndef PAGINATIONRESULT_H
#define PAGINATIONRESULT_H

#include "core_global.h"

class QJsonObject;
class CORE_EXPORT PaginationResult
{
public:
    PaginationResult();
    explicit PaginationResult(const int page, const int totalPage, const int totalResults);

    static PaginationResult* fromJson(const QJsonObject& jsonObject);

    int page() const;
    void setPage(int newPage);

    int totalPage() const;
    void setTotalPage(int newTotalPage);

    int totalResult() const;
    void setTotalResult(int newTotalResult);

private:
    int _page;
    int _totalPage;
    int _totalResult;
};

#endif // PAGINATIONRESULT_H
