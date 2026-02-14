#ifndef HOMECONTROL_H
#define HOMECONTROL_H

#include <QList>
#include <QObject>
#include <QQmlEngine>

#include "controls_global.h"

#include "sectionconfigmodel.h"

class CONTROLS_EXPORT HomeControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
public:
    ~HomeControl();

    Q_INVOKABLE void doStart();
signals:
    void sectionsChanged( const QVariant& sections );

private:
    QList<SectionConfigModel*> _sectionsConfig;
};

#endif // HOMECONTROL_H
