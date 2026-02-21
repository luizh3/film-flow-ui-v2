#include "notificationslistcontrol.h"

#include <core/model/entities/notification.h>
#include <core/model/entities/notificationreviewlike.h>
#include <core/model/result/notificationsresult.h>

#include <core/controller/notificationcontroller.h>
#include <core/helper/taskrunhelper.h>
#include <core/model/entities/user.h>
#include <core/model/result/paginationresult.h>

#include <network/request/paginationrequest.h>

NotificationsListControl::NotificationsListControl()
    : _notificationController{new NotificationController()}
    , _paginationRequest{new PaginationRequest()}
    , _notificationsListModel{}
{
    QObject::connect(&_notificationsListModel,
                     &NotificationsListModel::fetchNotifications,
                     this,
                     &NotificationsListControl::onFetchNotifications);
}

NotificationsListControl::~NotificationsListControl()
{
    QObject::disconnect(&_notificationsListModel,
                        &NotificationsListModel::fetchNotifications,
                        this,
                        &NotificationsListControl::onFetchNotifications);

    _notificationController->cancel();

    _notificationController->deleteLater();

    delete _paginationRequest;
}

void NotificationsListControl::onFetchNotifications()
{
    _paginationRequest->setPage(_paginationRequest->page() + 1);

    _notificationController->findAll(_paginationRequest)
        .then([this](NotificationsResult *notificationsResult) {
            onFetchEnded(notificationsResult);
        });
}

void NotificationsListControl::onFetchEnded(NotificationsResult *notificationsResult)
{
    if (!notificationsResult) {
        return;
    }

    const bool isLastPage = notificationsResult->pagination()->totalPage()
                            == _paginationRequest->page();
    _notificationsListModel.setIsReviewsEnded(isLastPage);

    const QList<Notification *> &notifications = notificationsResult->notifications();

    _notificationsListModel
        .onFetchEnded(notifications.count(),
                      [notifications](NotificationsListModel::CardNotification *cardNotification,
                                      const int index) {
                          NotificationsListControl::applyToCard(cardNotification,
                                                                notifications[index]);
                      });

    delete notificationsResult;
}

void NotificationsListControl::applyToCard(
    NotificationsListModel::CardNotification *cardNotification, Notification *notification)
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
    default:
        break;
    }

    cardNotification->isLoading = false;
}

NotificationsListModel *NotificationsListControl::model()
{
    return &_notificationsListModel;
}
