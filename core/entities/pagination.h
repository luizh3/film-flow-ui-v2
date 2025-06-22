#ifndef PAGINATION_H
#define PAGINATION_H

class QJsonObject;
class Pagination
{
public:
    Pagination();
    explicit Pagination( const int page, const int totalPage, const int totalResults );

    static Pagination* fromJson( const QJsonObject& jsonObject );

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

#endif // PAGINATION_H
