#include "settingscontrol.h"

#include <QVariantMap>

#include <core/manager/applicationmanager.h>

// #include <theme/themecolorfactory.h>

#include <ui/theme/factory/themecolorfactory.h>
#include <ui/theme/manager/themecolormanager.h>
#include <ui/theme/models/colorrole.h>

SettingsControl::SettingsControl()
    : _languages{}
// , _colorsItems{}
{
    initializeLanguages();
    initializeColors();
}

void SettingsControl::doStart()
{
    QVariantList langugesComboBoxDTO;

    for (const QVariant &languageVariant : _languages) {
        QVariantMap languageMap = languageVariant.toMap();

        const bool isCurrentLanguage = ApplicationManager::instance().languageManager().dsLocale()
                                       == languageMap["locale"].toString();

        langugesComboBoxDTO.append(QVariantMap{{"vText", languageMap["name"]},
                                               {"vImage", languageMap["source"]},
                                               {"vIsSelected", isCurrentLanguage}});
    }

    emit initialize(langugesComboBoxDTO, QVariant::fromValue(_colorsItems));
}

void SettingsControl::doSave(const int indexLanguageSelect, ColorItemModel *colorItem)
{
    const QString locale = _languages.at(indexLanguageSelect).toMap()["locale"].toString();

    if (colorItem) {
        ThemeColorManager::instance()->setRoleType(colorItem->roleType());
        ThemeColorManager::instance()->setTheme(ThemeColorFactory::byRole(colorItem->roleType()));
    }

    ApplicationManager::instance().languageManager().switchLanguage(locale);

    languageChanged();

    toastSuccess(tr("Success on save settings!"));
}

void SettingsControl::initializeLanguages()
{
    // TODO refactor to DTO
    _languages.append(QVariantMap{{"name", "Português ( Brasil )"},
                                  {"source", "qrc:/imagens/brasil-flag"},
                                  {"locale", "pt_BR"}});
    _languages.append(QVariantMap{{"name", "English ( United States )"},
                                  {"source", "qrc:/imagens/estados-unidos-flag"},
                                  {"locale", "en_US"}});
    _languages.append(QVariantMap{{"name", "Espanhol ( Espanha )"},
                                  {"source", "qrc:/imagens/espanha-flag"},
                                  {"locale", "es_ES"}});
}

void SettingsControl::initializeColors()
{
    ThemeColorManager::instance();

    const QList<ColorRole> colorsRole = {ColorRole::ORANGE,
                                         ColorRole::BLUE,
                                         ColorRole::GREEN,
                                         ColorRole::PURPLE,
                                         ColorRole::TEAL};

    const ColorRole currentRoleType = ThemeColorManager::instance()->roleType();

    for (const ColorRole &colorRole : colorsRole) {
        bool isSelected = colorRole == currentRoleType;

        _colorsItems.append(new ColorItemModel(colorRole,
                                               ThemeColorFactory::byRole(colorRole).primary500,
                                               isSelected));
    }
}
