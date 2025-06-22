#ifndef SECTIONSCONFIG_H
#define SECTIONSCONFIG_H

#include <QObject>

#include "core_global.h"

#include "typeprogramenum.h"

class QJsonObject;
class CORE_EXPORT SectionsConfig : public QObject {
    Q_OBJECT
    Q_PROPERTY( QString key READ key CONSTANT )
    Q_PROPERTY( QString name READ name CONSTANT )
    Q_PROPERTY( TypeProgram::TypeProgramEnum tpProgram READ tpProgram CONSTANT )
public:
    SectionsConfig();
    explicit SectionsConfig( const TypeProgramEnum tpProgram, const QString& name, const QString& key );

    QString key() const;
    void setKey(const QString &newKey);

    QString name() const;
    void setName(const QString &newName);

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

    static SectionsConfig* fromJson( const QJsonObject& jsonObject );
private:
    TypeProgramEnum _tpProgram;
    QString _name;
    QString _key;
};

#endif // SECTIONSCONFIG_H
