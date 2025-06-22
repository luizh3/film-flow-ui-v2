#ifndef SECTIONREQUEST_H
#define SECTIONREQUEST_H

#include <QString>

#include <core_global.h>

#include <entities/typeprogramenum.h>

class QUrlQuery;
class CORE_EXPORT SectionRequest {
public:
    SectionRequest();

    int page() const;
    void setPage(int newPage);

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

    QString key() const;
    void setKey(const QString &newKey);

    QString language() const;
    void setLanguage(const QString &newLanguage);

    QUrlQuery toQuerys() const;

private:
    int _page;
    TypeProgramEnum _tpProgram;
    QString _key;
    QString _language;
};

#endif // SECTIONREQUEST_H
