#ifndef PROGRAMCONFIG_H
#define PROGRAMCONFIG_H

#include <QMap>
#include <QString>

#include <core_global.h>

#include "typeprogramenum.h"

class Genre;
class QJsonObject;
class CORE_EXPORT ProgramConfig {
public:
    ~ProgramConfig();

    ProgramConfig();
    explicit ProgramConfig(const TypeProgramEnum tpProgram, const QMap<int, Genre *> &genresById);

    TypeProgramEnum tpProgram() const;
    void setTpProgram( TypeProgramEnum newTpProgram);

    static ProgramConfig* fromJson( const QJsonObject& jsonDocument );

    QMap<int, Genre *> genresById() const;
    void setGenresById(const QMap<int, Genre *> &newGenresById);

private:
    TypeProgramEnum _tpProgram;
    QMap<int, Genre *> _genresById;
};

#endif // PROGRAMCONFIG_H
