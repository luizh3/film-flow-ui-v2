#ifndef PAGINATIONREQUEST_H
#define PAGINATIONREQUEST_H

#include <core_global.h>

class QUrlQuery;
class CORE_EXPORT PaginationRequest
{
public:
    PaginationRequest();

    int page() const;
    void setPage(int newPage);

    QUrlQuery toQuerys() const;

private:
    int _page;
};

#endif // PAGINATIONREQUEST_H
