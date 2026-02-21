#ifndef PRESENTERTYPEPROGRAMENUM_H
#define PRESENTERTYPEPROGRAMENUM_H

#include <models_global.h>

#include <QObject>
#include <QtGlobal>
#include <qqmlregistration.h>

namespace PresenterTypeProgram {
Q_NAMESPACE_EXPORT(MODELS_EXPORT)
QML_NAMED_ELEMENT(PresenterTypeProgramEnum)

enum class PresenterTypeProgramEnum : qint8 { UNKNOW = -1, MOVIE = 1, TV = 2 };
Q_ENUM_NS(PresenterTypeProgramEnum)

} // namespace PresenterTypeProgram

using PresenterTypeProgramEnum = PresenterTypeProgram::PresenterTypeProgramEnum;

#endif
