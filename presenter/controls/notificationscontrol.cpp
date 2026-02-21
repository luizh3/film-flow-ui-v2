#include "notificationscontrol.h"

#include <core/manager/notificationmanager.h>

NotificationsControl::NotificationsControl()
{
    QObject::connect(NotificationManager::instance(),
                     &NotificationManager::newNotification,
                     this,
                     &NotificationsControl::newNotification);
}
