#ifndef NOTIFICATIONSLISTCONTROL_H
#define NOTIFICATIONSLISTCONTROL_H

#include <QObject>
#include <QQmlEngine>

#include <ui/models/notificationslistmodel.h>

class Notification;
class NotificationsResult;
class PaginationRequest;
class NotificationController;
class NotificationsListControl : public QObject
{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(NotificationsListModel* model READ model CONSTANT)
public:
    NotificationsListControl();
    ~NotificationsListControl();

    void onFetchNotifications();

    QList<NotificationsListModel::CardNotification*> toCards(
        NotificationsResult* notificationsResult);

    NotificationsListModel* model();

private:
    PaginationRequest* _paginationRequest;
    NotificationController* _notificationController;

    NotificationsListModel _notificationsListModel;

    void onFetchEnded(NotificationsResult* notificationsResult);

    static void applyToCard(NotificationsListModel::CardNotification* cardNotification,
                            Notification* notification);
};

#endif // NOTIFICATIONSLISTCONTROL_H
