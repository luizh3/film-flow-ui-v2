#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QQmlEngine>

#include <controls_global.h>

#include "control.h"

class CONTROLS_EXPORT MainControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    virtual void toastSuccess(const QString& message);
    virtual void toastError(const QString& message);
    virtual void toastWarning(const QString& message);
signals:
    void notifierToastSuccess(const QString& message);
    void notifierToastError(const QString& message);
    void notifierToastWarning(const QString& message);
};

#endif // MAINCONTROL_H
