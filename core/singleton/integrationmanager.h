#ifndef INTEGRATIONMANAGER_H
#define INTEGRATIONMANAGER_H

#include <entities/integration.h>

using MapIntegrationType = std::unordered_map<Integration::IntegrationType, Integration*>;

class IntegrationManager {
public:
    IntegrationManager();

    static IntegrationManager& instance();

   MapIntegrationType integrations() const;

    void setIntegrations( const MapIntegrationType& newIntegrations );
    void addIntegration( const Integration::IntegrationType type, Integration* integration );

    Integration* integrationByType( const Integration::IntegrationType type );

private:
    MapIntegrationType _integrations;
};

#endif // INTEGRATIONMANAGER_H
