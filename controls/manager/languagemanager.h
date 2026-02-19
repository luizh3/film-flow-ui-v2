#ifndef LANGUAGEMANAGER_H
#define LANGUAGEMANAGER_H

#include <QCoreApplication>
#include <QQmlEngine>
#include <QTranslator>

#include <controls_global.h>

class CONTROLS_EXPORT LanguageManager
{
public:
    LanguageManager();

    void intialize(QCoreApplication *app, QQmlEngine *engine);

    void switchLanguage(const QString &locale);

    QString dsLocale() const;
    QString dsLocaleBCP47();

private:
    QCoreApplication *_app;
    QQmlEngine *_engine;
    QTranslator _translator;
    QString _dsLocale;
};

#endif // LANGUAGEMANAGER_H
