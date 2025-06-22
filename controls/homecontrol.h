#ifndef HOMECONTROL_H
#define HOMECONTROL_H

#include <QObject>
#include <QQmlEngine>

#include "controls_global.h"

class SectionsConfig;
class CONTROLS_EXPORT HomeControl : public QObject {
    Q_OBJECT
    QML_ELEMENT
public:
    Q_INVOKABLE void doStart();
signals:
    void sectionsChanged( const QVariant& sections );
};

#endif // HOMECONTROL_H
