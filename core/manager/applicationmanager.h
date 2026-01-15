#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "languagemanager.h"
#include <core_global.h>

class Session;
class Configs;
class CORE_EXPORT ApplicationManager {
public:
    ~ApplicationManager();
    ApplicationManager();

    static ApplicationManager& instance();

    Session *session() const;
    void setSession(Session *newSession);

    Configs *configs() const;
    void setConfigs(Configs *newConfigs);

    LanguageManager &languageManager();

private:
    Session* _session;
    Configs* _configs;
    LanguageManager _languageManager;
};

#endif // APPLICATIONMANAGER_H
