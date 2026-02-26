import QtQuick

import Ui.Components

import Ui.Screens

import Presenter.Controls

HeaderForm {
    id: root

    signal search(var dsText)
    signal notifications

    signal programSelected(var id, var tpProgram)

    vUserImage: UiControlManager.user?.avatarUrl || "qrc:/imagens/no-user.png"

    function clearSearch() {
        root.searchTextField.clear()
    }

    function _handleSearchConfirmed() {
        root.search(root.searchTextField.vText)
    }

    notificationButton.onClicked: () => root.notifications()

    searchTextField.onConfirmed: () => root._handleSearchConfirmed()

    NotificationsControl {
        onNewNotification: function (count) {
            root.notificationButton.addNotificationCount(count)
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
