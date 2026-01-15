#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include <QObject>
#include <core_global.h>

#include "typenotificationenum.h"

class QJsonDocument;
class CORE_EXPORT Notification : public QObject
{
    Q_OBJECT
public:
    virtual TypeNotificationEnum type() = 0;

    virtual void fromJson(const QJsonObject& jsonDocument) = 0;

private:
};

#endif // NOTIFICATION_H
