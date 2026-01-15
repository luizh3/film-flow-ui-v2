#include "notificationslistmodel.h"

#include "notification.h"
#include "notificationreviewlike.h"
#include "notificationsresult.h"

#include "helper/cardsfetchhelper.h"

#include <core/controller/notificationcontroller.h>
#include <core/entities/pagination.h>
#include <core/helper/taskrunhelper.h>
#include <network/request/paginationrequest.h>

namespace {
constexpr int NR_REVIEWS_BY_PAGE = 10;
}

NotificationsListModel::~NotificationsListModel()
{
    delete _paginationRequest;
    delete _notificationController;

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

    QFutureWatcher<NotificationsResult *> *future = TaskRunHelper::async<NotificationsResult *>(
        [&]() { return onFetchStarted(); });

    QObject::connect(future,
                     &QFutureWatcher<NotificationsResult *>::finished,
                     this,
                     [this, future]() { onFetchEnded(future); });
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
                                          {IsLoading, "isLoading"}};

    return mapping;
}

NotificationsResult *NotificationsListModel::onFetchStarted()
{
    return _notificationController->findAll(_paginationRequest);
}

void NotificationsListModel::onFetchEnded(QFutureWatcher<NotificationsResult *> *future)
{
    if (future->isFinished() && !future->isCanceled()) {
        std::unique_ptr<NotificationsResult> notificationsResult(future->result());

        _isReviewsEnded = notificationsResult->pagination()->totalPage()
                          == _paginationRequest->page();

        updateCardsNotification(_fetchingNotificatiosCard, notificationsResult->notifications());

        _isFetching = false;
    }

    future->deleteLater();
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
        cardNotification->description = QString("<b>%0</b> liked your review on the <b>%1</b>")
                                            .arg(notificationReviewLike->actorName(),
                                                 notificationReviewLike->programTitle());
        cardNotification->icon = "qrc:/icons/favorite";
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
    , isLoading{true}
{}
