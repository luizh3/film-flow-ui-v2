import QtQuick

import Presenter.Controls

ProfileScreenForm {
    id: root

    function _handleClose() {
        root.close()
    }

    function _handleUserChanged(user) {
        root.vUser = user
    }

    function _handleOnCompleted() {
        control.doStart()
    }

    backButtonNavigation.onClicked: root._handleClose()
    goBackButton.onClicked: root._handleClose()

    Component.onCompleted: root._handleOnCompleted()

    ProfileScreenControl {
        id: control

        onUserChanged: user => root._handleUserChanged(user)
    }
}
