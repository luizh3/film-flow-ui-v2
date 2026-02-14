#ifndef TYPENOTIFICATIONENUM_H
#define TYPENOTIFICATIONENUM_H

#include <core_global.h>

#include <QMap>
#include <QtGlobal>

namespace TypeNotificaton {
Q_NAMESPACE_EXPORT(CORE_EXPORT)
enum class TypeNotificationEnum : qint8 { UNKNOW = -1, REVIEW_LIKE = 1 };
Q_ENUM_NS(TypeNotificationEnum)

inline const TypeNotificationEnum fromString(const QString& value)
{
    static const QMap<QString, TypeNotificationEnum> mapFromString{
        {QStringLiteral("REVIEW_LIKE"), TypeNotificationEnum::REVIEW_LIKE}};

    return mapFromString.value(value, TypeNotificationEnum::UNKNOW);
}

inline const QString toString(const TypeNotificationEnum tpProgram)
{
    static const QMap<TypeNotificationEnum, QString> mapToString{
        {TypeNotificationEnum::REVIEW_LIKE, QStringLiteral("REVIEW_LIKE")}};

    return mapToString.value(tpProgram, QStringLiteral(""));
}
} // namespace TypeNotificaton

using TypeNotificationEnum = TypeNotificaton::TypeNotificationEnum;

#endif // TYPENOTIFICATIONENUM_H
