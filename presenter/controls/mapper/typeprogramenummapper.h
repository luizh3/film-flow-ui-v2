#ifndef TYPEPROGRAMENUMMAPPER_H
#define TYPEPROGRAMENUMMAPPER_H

#include <core/model/enum/typeprogramenum.h>
#include <presenter/models/enum/presentertypeprogramenum.h>

class TypeProgramEnumMapper
{
public:
    static PresenterTypeProgramEnum toModel(const TypeProgramEnum typeProgramEnum);
    static TypeProgramEnum toEntity(const PresenterTypeProgramEnum presenterTypeProgramEnum);
};

#endif // TYPEPROGRAMENUMMAPPER_H
