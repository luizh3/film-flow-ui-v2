#ifndef NOTIFICATIONSLISTMODEL_H
#define NOTIFICATIONSLISTMODEL_H

#include <QAbstractListModel>
#include <QFutureWatcher>
#include <QMap>
#include <QQmlEngine>

#include <models_global.h>

class Notification;
class NotificationsResult;
class PaginationRequest;
class NotificationController;
class MODELS_EXPORT NotificationsListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    ~NotificationsListModel();
    NotificationsListModel();

    enum Roles { Description, Icon, IsLoading };

    struct CardNotification
    {
        CardNotification();

        QString description;
        QString icon;
        bool isLoading;
    };

    virtual int rowCount(const QModelIndex& parent) const override;

    virtual QVariant data(const QModelIndex& index, int role) const override;

    virtual void fetchMore(const QModelIndex& parent) override;

    virtual bool canFetchMore(const QModelIndex& parent) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    NotificationsResult* onFetchStarted();
    void onFetchEnded(QFutureWatcher<NotificationsResult*>* future);
    void updateCardsNotification(const QList<CardNotification*>& cardsNotification,
                                 const QList<Notification*>& notifications);
    static void updateCardNotification(CardNotification* cardNotification,
                                       Notification* notification);

    bool _isReviewsEnded;
    bool _isFetching;

    PaginationRequest* _paginationRequest;
    NotificationController* _notificationController;

    QList<CardNotification*> _fetchingNotificatiosCard;
    QList<CardNotification*> _notificationsCard;
};

#endif // NOTIFICATIONSLISTMODEL_H
