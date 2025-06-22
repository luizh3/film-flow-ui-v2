#ifndef PROGRAMCONFIG_H
#define PROGRAMCONFIG_H

#include <QList>
#include <QString>

#include <core_global.h>

#include "typeprogramenum.h"

class Genre;
class QJsonObject;
class CORE_EXPORT ProgramConfig {
public:
    ~ProgramConfig();

    ProgramConfig();
    explicit ProgramConfig( const TypeProgramEnum tpProgram, const QList<Genre*>& genres );

    TypeProgramEnum tpProgram() const;
    void setTpProgram( TypeProgramEnum newTpProgram);

    QList<Genre*> genres() const;
    void setGenres(const QList<Genre*> &newGenres);

    static ProgramConfig* fromJson( const QJsonObject& jsonDocument );

private:
    TypeProgramEnum _tpProgram;
    QList<Genre*> _genres;
};

#endif // PROGRAMCONFIG_H
