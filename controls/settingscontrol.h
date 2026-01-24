#ifndef SETTINGSCONTROL_H
#define SETTINGSCONTROL_H

#include <QObject>
#include <QQmlEngine>
#include <QVariantList>

#include <controls_global.h>

#include "control.h"

#include <ui/theme/models/coloritemmodel.h>

class CONTROLS_EXPORT SettingsControl : public Control
{
    Q_OBJECT
    QML_ELEMENT
public:
    SettingsControl();

    Q_INVOKABLE void doStart();
    Q_INVOKABLE void doSave(const int indexLanguageSelect, ColorItemModel *colorItem);
signals:
    void initialize(QVariant languages, QVariant colors);

private:
    QVariantList _languages;
    QList<ColorItemModel *> _colorsItems;

    void initializeLanguages();
    void initializeColors();
};

#endif // SETTINGSCONTROL_H
