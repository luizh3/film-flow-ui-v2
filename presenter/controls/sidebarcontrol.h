#ifndef SIDEBARCONTROL_H
#define SIDEBARCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <controls_global.h>

#include "control.h"

class CONTROLS_EXPORT SideBarControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    virtual void languageChanged();
};

#endif // SIDEBARCONTROL_H
