#ifndef NOTIFICATIONSLISTMODEL_H
#define NOTIFICATIONSLISTMODEL_H

#include <QAbstractListModel>
#include <QFutureWatcher>
#include <QQmlEngine>

#include <models_global.h>

class MODELS_EXPORT NotificationsListModel : public QAbstractListModel
{
    Q_OBJECT
    QML_ELEMENT
public:
    ~NotificationsListModel();
    NotificationsListModel();

    enum Roles { Description, Icon, IsLoading, ActorAvatarUrl };

    struct MODELS_EXPORT CardNotification
    {
        CardNotification();

        QString description;
        QString icon;
        QString actorAvatarUrl;
        bool isLoading;
    };

    virtual int rowCount(const QModelIndex& parent) const override;

    virtual QVariant data(const QModelIndex& index, int role) const override;

    virtual void fetchMore(const QModelIndex& parent) override;

    virtual bool canFetchMore(const QModelIndex& parent) const override;

    QHash<int, QByteArray> roleNames() const override;

    void onFetchEnded(const int nrItensFetch,
                      std::function<void(NotificationsListModel::CardNotification*, const int index)>
                          bindCardCallback);

    void setIsReviewsEnded(const bool isReviewsEnded);

signals:
    void fetchNotifications();

private:
    void updateCardsNotification(const int nrItensFetch,
                                 std::function<void(NotificationsListModel::CardNotification*,
                                                    const int index)> bindCardCallback);

    bool _isReviewsEnded;
    bool _isFetching;

    QList<CardNotification*> _fetchingNotificatiosCard;
    QList<CardNotification*> _notificationsCard;
};

#endif // NOTIFICATIONSLISTMODEL_H
