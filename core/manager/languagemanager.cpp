#include "languagemanager.h"

namespace {
constexpr const char *DS_NAME_FILE_TRADUTION = ":/i18n/film_flow_%0.qm";
}

LanguageManager::LanguageManager()
    : _app{nullptr}
    , _engine{nullptr}
    , _translator{}
    , _dsLocale{QStringLiteral("en_US")}
{}

void LanguageManager::intialize(QCoreApplication *app, QQmlEngine *engine)
{
    _app = app;
    _engine = engine;
}

void LanguageManager::switchLanguage(const QString &locale)
{
    _dsLocale = locale;

    _app->removeTranslator(&_translator);

    const QString dsDefaultLocale = "en_US";

    if (locale == dsDefaultLocale) {
        _engine->retranslate();
        return;
    }

    if (_translator.load(QString(DS_NAME_FILE_TRADUTION).arg(locale))) {
        _app->installTranslator(&_translator);
        _engine->retranslate();
    }
}

QString LanguageManager::dsLocale() const
{
    return QLocale(_dsLocale).name();
}

QString LanguageManager::dsLocaleBCP47()
{
    return QLocale(_dsLocale).bcp47Name();
}
