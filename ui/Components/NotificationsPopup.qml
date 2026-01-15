import QtQuick

import Ui.Models
import Ui.Theme

NotificationsPopupForm {
    id: root

    notificationsList.model: NotificationsListModel {}

    notificationsList.delegate: NotificationCard {
        id: notificationCard

        width: ListView.view.width

        required property string description
        required property string icon
        required property bool isLoading

        vDescription: notificationCard.description
        vIcon: notificationCard.icon
        vIsLoading: notificationCard.isLoading
    }

    function positionerByElement(element) {
        const elementInstance = element.mapToItem(parent, 0, element.height)
        root.x = elementInstance.x + element.width - width
        root.y = elementInstance.y + Spacings.md
    }
}
