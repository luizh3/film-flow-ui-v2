#include "notificationslistmodel.h"

#include "helper/cardsfetchhelper.h"

#include <core/model/entities/notification.h>
#include <core/model/entities/notificationreviewlike.h>
#include <core/model/result/notificationsresult.h>

#include <core/controller/notificationcontroller.h>
#include <core/helper/taskrunhelper.h>
#include <core/model/entities/user.h>
#include <core/model/result/paginationresult.h>

#include <network/request/paginationrequest.h>

namespace {
constexpr int NR_REVIEWS_BY_PAGE = 10;
}

NotificationsListModel::~NotificationsListModel()
{
    _notificationController->cancel();

    _notificationController->deleteLater();

    delete _paginationRequest;

    qDeleteAll(_notificationsCard);
}

NotificationsListModel::NotificationsListModel()
    : _isReviewsEnded{false}
    , _isFetching{false}
    , _paginationRequest{new PaginationRequest()}
    , _notificationController{new NotificationController()}
    , _fetchingNotificatiosCard{}
    , _notificationsCard{}
{}

int NotificationsListModel::rowCount(const QModelIndex &parent) const
{
    return _notificationsCard.count();
}

QVariant NotificationsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    const int row = index.row();

    switch (role) {
    case Description:
        return _notificationsCard.at(row)->description;
    case Icon:
        return _notificationsCard.at(row)->icon;
    case IsLoading:
        return _notificationsCard.at(row)->isLoading;
    case ActorAvatarUrl:
        return _notificationsCard.at(row)->actorAvatarUrl;
    default:
        return QVariant();
    }
}

void NotificationsListModel::fetchMore(const QModelIndex &parent)
{
    if (parent.isValid() || _isFetching || _isReviewsEnded) {
        return;
    }

    _isFetching = true;

    _paginationRequest->setPage(_paginationRequest->page() + 1);

    CardFetchHelper::appendFetchingCards<CardNotification>(
        _notificationsCard,
        _fetchingNotificatiosCard,
        NR_REVIEWS_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new CardNotification(); });

    onFetchStarted().then(
        [&](NotificationsResult *notificationsResult) { onFetchEnded(notificationsResult); });
}

bool NotificationsListModel::canFetchMore(const QModelIndex &parent) const
{
    if (parent.isValid()) {
        return false;
    }

    return !_isFetching && !_isReviewsEnded;
}

QHash<int, QByteArray> NotificationsListModel::roleNames() const
{
    static QHash<int, QByteArray> mapping{{Description, "description"},
                                          {Icon, "icon"},
                                          {IsLoading, "isLoading"},
                                          {ActorAvatarUrl, "actorAvatarUrl"}};

    return mapping;
}

QFuture<NotificationsResult *> NotificationsListModel::onFetchStarted()
{
    return _notificationController->findAll(_paginationRequest);
}

void NotificationsListModel::onFetchEnded(NotificationsResult *notificationsResult)
{

    if (!notificationsResult) {
        _isFetching = false;
        return;
    }

    _isReviewsEnded = notificationsResult->pagination()->totalPage() == _paginationRequest->page();

    updateCardsNotification(_fetchingNotificatiosCard, notificationsResult->notifications());

    _isFetching = false;

    delete notificationsResult;
}

void NotificationsListModel::updateCardsNotification(
    const QList<CardNotification *> &cardsNotification, const QList<Notification *> &notifications)
{
    CardFetchHelper::updateCards<CardNotification, Notification>(
        _notificationsCard,
        _fetchingNotificatiosCard,
        notifications,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        &NotificationsListModel::updateCardNotification);
}

void NotificationsListModel::updateCardNotification(CardNotification *cardNotification,
                                                    Notification *notification)
{
    switch (notification->type()) {
    case TypeNotificationEnum::REVIEW_LIKE: {
        const NotificationReviewLike *notificationReviewLike = static_cast<NotificationReviewLike *>(
            notification);
        cardNotification->description = QString(tr("<b>%0</b> liked your review on the <b>%1</b>"))
                                            .arg(notificationReviewLike->actor()->name(),
                                                 notificationReviewLike->programTitle());
        cardNotification->icon = "qrc:/icons/favorite";
        cardNotification->actorAvatarUrl = notificationReviewLike->actor()->avatarUrl().isEmpty()
                                               ? "qrc:/imagens/no-user.png"
                                               : notificationReviewLike->actor()->avatarUrl();

        break;
    }
    default: {
        break;
    }
    }

    cardNotification->isLoading = false;
}

NotificationsListModel::CardNotification::CardNotification()
    : description{QStringLiteral("")}
    , icon{QStringLiteral("")}
    , actorAvatarUrl{QStringLiteral("")}
    , isLoading{true}
{}
