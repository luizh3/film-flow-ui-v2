#ifndef SECTIONCONFIGMODEL_H
#define SECTIONCONFIGMODEL_H

#include <QObject>

#include <models_global.h>

#include <model/enum/typeprogramenum.h>

class MODELS_EXPORT SectionConfigModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(TypeProgram::TypeProgramEnum tpProgram READ tpProgram WRITE setTpProgram NOTIFY
                   tpProgramChanged FINAL)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged FINAL)
    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged FINAL)
public:
    SectionConfigModel();
    SectionConfigModel(TypeProgramEnum tpProgram, QString name, QString key);

    TypeProgramEnum tpProgram() const;
    void setTpProgram(TypeProgramEnum newTpProgram);

    QString name() const;
    void setName(const QString &newName);

    QString key() const;
    void setKey(const QString &newKey);

signals:
    void tpProgramChanged();
    void nameChanged();
    void keyChanged();

private:
    TypeProgramEnum _tpProgram;
    QString _name;
    QString _key;
};

#endif // SECTIONCONFIGMODEL_H
