#include "typeprogramenummapper.h"

PresenterTypeProgramEnum TypeProgramEnumMapper::toModel(const TypeProgramEnum typeProgramEnum)
{
    return PresenterTypeProgramEnum(typeProgramEnum);
}

TypeProgramEnum TypeProgramEnumMapper::toEntity(
    const PresenterTypeProgramEnum presenterTypeProgramEnum)
{
    return TypeProgramEnum(presenterTypeProgramEnum);
}
