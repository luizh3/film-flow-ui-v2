import QtQuick

import Ui.Theme

import Presenter.Controls

NotificationsPopupForm {
    id: root

    notificationsList.model: notificationListControl.model

    notificationsList.delegate: NotificationCard {
        id: notificationCard

        width: ListView.view.width

        required property string description
        required property string icon
        required property bool isLoading
        required property string actorAvatarUrl

        vDescription: notificationCard.description
        vIcon: notificationCard.icon
        vIsLoading: notificationCard.isLoading
        vActorAvatarUrl: notificationCard.actorAvatarUrl
    }

    function positionerByElement(element) {
        const elementInstance = element.mapToItem(parent, 0, element.height)
        root.x = elementInstance.x + element.width - width
        root.y = elementInstance.y + Spacings.md
    }

    NotificationsListControl {
        id: notificationListControl
    }
}
