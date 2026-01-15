#include "settingscontrol.h"

#include <QVariantMap>

#include <core/manager/applicationmanager.h>

SettingsControl::SettingsControl()
{
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

    emit initialize(langugesComboBoxDTO);
}

void SettingsControl::doSave(const int indexLanguageSelect)
{
    const QString locale = _languages.at(indexLanguageSelect).toMap()["locale"].toString();

    ApplicationManager::instance().languageManager().switchLanguage(locale);

    languageChanged();

    toastSuccess(tr("Success on save settings!"));
}
