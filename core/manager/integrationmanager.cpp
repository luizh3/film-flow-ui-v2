#include "integrationmanager.h"

IntegrationManager::IntegrationManager() {}

IntegrationManager& IntegrationManager::instance() {
    static IntegrationManager integrationManager;
    return integrationManager;
}

MapIntegrationType IntegrationManager::integrations() const {
    return _integrations;
}

void IntegrationManager::setIntegrations( const MapIntegrationType& newIntegrations ) {
    _integrations = newIntegrations;
}

void IntegrationManager::addIntegration( const Integration::IntegrationType type, Integration* integration ) {

    const bool hasElement = _integrations.find(type) != _integrations.cend();

    if( hasElement ){
        delete _integrations[type];
        _integrations.erase(type);
    }

    _integrations.emplace( type, integration );
}

Integration* IntegrationManager::integrationByType( const Integration::IntegrationType type ){
    return _integrations[type];
}
