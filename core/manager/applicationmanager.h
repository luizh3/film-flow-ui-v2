#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

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

private:
    Session* _session;
    Configs* _configs;
};

#endif // APPLICATIONMANAGER_H
