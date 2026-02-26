import QtQuick

import Ui.Components

Item {
    id: root

    enum Popup {
        Notification,
        SearchProgramResult
    }

    property var activePopups: []

    function open(type, positionerElement, setupCallback) {

        if (activePopups[type]) {
            var popup = activePopups[type]
            activePopups[type] = null
            popup.close()
            popup.destroy()
        }

        var popup = root._getByEnum(type).createObject(root)
        popup.positionerByElement(positionerElement)

        if (setupCallback) {
            setupCallback(popup)
        }

        popup.closed.connect(() => {
                                 popup.destroy()
                                 activePopups[type] = null
                             })

        activePopups[type] = popup
        popup.open()
    }

    function _getByEnum(type) {
        switch (type) {
        case PopupManager.Popup.Notification:
            return notificationsPopupComponent
        case PopupManager.Popup.SearchProgramResult:
            return searchProgramResultPopupComponent
        }
    }

    Component {
        id: notificationsPopupComponent

        NotificationsPopup {
            id: notificationsPopup
        }
    }

    Component {
        id: searchProgramResultPopupComponent

        SearchProgramResultPopup {
            id: searchProgramResultPopup
        }
    }
}
