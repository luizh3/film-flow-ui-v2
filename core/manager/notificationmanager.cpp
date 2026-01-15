#include "notificationmanager.h"

NotificationManager::NotificationManager()
    : _notificationWs{nullptr}
{}

NotificationManager *NotificationManager::instance()
{
    static NotificationManager notificationManager;
    return &notificationManager;
}

void NotificationManager::attach(NotificationWs *notificationWs)
{
    _notificationWs = notificationWs;

    QObject::connect(_notificationWs,
                     &NotificationWs::newNotification,
                     this,
                     &NotificationManager::newNotification);
}
