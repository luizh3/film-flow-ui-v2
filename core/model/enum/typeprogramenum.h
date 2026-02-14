#ifndef TYPEPROGRAMENUM_H
#define TYPEPROGRAMENUM_H

#include <core_global.h>

#include <QtGlobal>
#include <QMap>

namespace TypeProgram {
Q_NAMESPACE_EXPORT( CORE_EXPORT )
enum class TypeProgramEnum : qint8 {
    UNKNOW = -1,
    MOVIE = 1,
    TV = 2
};
Q_ENUM_NS( TypeProgramEnum )

inline const TypeProgramEnum fromString( const QString& value ) {

    static const QMap<QString, TypeProgramEnum> mapFromString {
        { QStringLiteral("MOVIE"), TypeProgramEnum::MOVIE },
        { QStringLiteral("TV"), TypeProgramEnum::TV }
    };

    return mapFromString.value( value, TypeProgramEnum::UNKNOW );
}

inline const QString toString( const TypeProgramEnum tpProgram ) {

    static const QMap<TypeProgramEnum, QString> mapToString {
        { TypeProgramEnum::MOVIE, QStringLiteral("MOVIE") },
        { TypeProgramEnum::TV, QStringLiteral("TV") }
    };

    return mapToString.value( tpProgram, QStringLiteral("") );
}
}

using TypeProgramEnum = TypeProgram::TypeProgramEnum;

#endif // TYPEPROGRAMENUM_H
