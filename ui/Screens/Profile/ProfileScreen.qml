import QtQuick

import controls 1.0

ProfileScreenForm {
    id: root

    function _handleClose() {
        root.close()
    }

    backButtonNavigation.onClicked: root._handleClose()
    goBackButton.onClicked: root._handleClose()

    function _handleUserChanged(user) {
        root.vUser = user
    }

    function _handleOnCompleted() {
        control.doStart()
    }

    ProfileScreenControl {
        id: control

        onUserChanged: user => root._handleUserChanged(user)
    }

    Component.onCompleted: root._handleOnCompleted()
}
