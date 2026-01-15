import QtQuick

import Ui.Components

import controls 1.0

HeaderForm {
    id: root

    signal search(var dsText)

    signal programSelected(var id, var tpProgram)

    function _handleProgramSelected(id, tpProgram) {
        root.searchProgramTextField.clear()
        root.programSelected(id, tpProgram)
    }

    function _handleOpenNotificationPopup() {
        var popup = notificationsPopupComponent.createObject(root)
        popup.positionerByElement(root.notificationButton)
        popup.closed.connect(() => {
                                 popup.destroy()
                             })
        popup.open()
    }

    function _handleOpenProgramSearchPopup(dsQuery) {
        var popup = searchProgramResultPopupComponent.createObject(root)
        popup.positionerByElement(root.searchProgramTextField)
        popup.selected.connect(root._handleProgramSelected)
        popup.closed.connect(() => {
                                 popup.destroy()
                             })
        popup.vDsQuery = dsQuery
        popup.open()
    }

    notificationButton.onClicked: root._handleOpenNotificationPopup()

    function _handleSearchConfirmed() {

        if (!root.vIsUsingSearchPopup) {
            root.search(root.searchProgramTextField.vText)
            return
        }

        root._handleOpenProgramSearchPopup(root.searchProgramTextField.vText)
    }

    searchProgramTextField.onConfirmed: () => root._handleSearchConfirmed()

    NotificationsControl {
        onNewNotification: function (count) {
            notificationButton.addNotificationCount(count)
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
