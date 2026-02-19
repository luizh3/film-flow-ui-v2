#include "notificationslistmodel.h"

#include "helper/cardsfetchhelper.h"

namespace {
constexpr int NR_REVIEWS_BY_PAGE = 10;
}

NotificationsListModel::~NotificationsListModel()
{
    qDeleteAll(_notificationsCard);
}

NotificationsListModel::NotificationsListModel()
    : _isReviewsEnded{false}
    , _isFetching{false}
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

    CardFetchHelper::appendFetchingCards<CardNotification>(
        _notificationsCard,
        _fetchingNotificatiosCard,
        NR_REVIEWS_BY_PAGE,

        [this](int first, int last) { beginInsertRows(QModelIndex(), first, last); },

        [this]() { endInsertRows(); },

        []() { return new CardNotification(); });

    emit fetchNotifications();
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

void NotificationsListModel::onFetchEnded(
    const int nrItensFetch,
    std::function<void(NotificationsListModel::CardNotification *, const int index)> bindCardCallback)
{
    updateCardsNotification(nrItensFetch, bindCardCallback);

    _isFetching = false;
}

void NotificationsListModel::updateCardsNotification(
    const int nrItensFetch,
    std::function<void(NotificationsListModel::CardNotification *, const int index)> bindCardCallback)
{
    CardFetchHelper::updateCards<CardNotification>(
        _notificationsCard,
        _fetchingNotificatiosCard,
        nrItensFetch,

        [this](int first, int last) { beginRemoveRows(QModelIndex(), first, last); },

        [this]() { endRemoveRows(); },

        [this](int first, int last) { emit dataChanged(index(first), index(last)); },

        bindCardCallback);
}

NotificationsListModel::CardNotification::CardNotification()
    : description{QStringLiteral("")}
    , icon{QStringLiteral("")}
    , actorAvatarUrl{QStringLiteral("")}
    , isLoading{true}
{}

void NotificationsListModel::setIsReviewsEnded(const bool isReviewsEnded)
{
    _isReviewsEnded = isReviewsEnded;
}
