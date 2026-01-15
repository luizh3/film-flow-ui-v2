#ifndef SETTINGSCONTROL_H
#define SETTINGSCONTROL_H

#include <QObject>
#include <QQmlEngine>
#include <QVariantList>

#include <controls_global.h>

#include "control.h"

class CONTROLS_EXPORT SettingsControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    explicit SettingsControl();

    Q_INVOKABLE void doStart();
    Q_INVOKABLE void doSave(const int indexLanguageSelect);
signals:
    void initialize(QVariant languages);

private:
    QVariantList _languages;
};

#endif // SETTINGSCONTROL_H
