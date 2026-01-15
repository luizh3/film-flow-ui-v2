#ifndef MULTIDETAILSREQUEST_H
#define MULTIDETAILSREQUEST_H

#include <QString>

#include <core_global.h>

class QUrlQuery;
class CORE_EXPORT MultiDetailsRequest
{
public:
    MultiDetailsRequest();

    QUrlQuery toQuerys() const;

    QString tpProgram() const;
    void setTpProgram(const QString &newTpProgram);

    QString dsLanguage() const;
    void setDsLanguage(const QString &newDsLanguage);

private:
    QString _tpProgram;
    QString _dsLanguage;
};

#endif // MULTIDETAILSREQUEST_H
