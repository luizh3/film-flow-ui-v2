#ifndef MULTIREQUEST_H
#define MULTIREQUEST_H

#include <QString>

#include <core_global.h>

class QUrlQuery;
class CORE_EXPORT MultiRequest
{
public:
    MultiRequest();

    QString dsQuery() const;
    void setDsQuery(const QString &newDsQuery);

    int page() const;
    void setPage(int newPage);

    QUrlQuery toQuerys() const;

    QString dsLanguage() const;
    void setDsLanguage(const QString &newDsLanguage);

private:
    QString _dsQuery;
    QString _dsLanguage;
    int _page;
};

#endif // MULTIREQUEST_H
