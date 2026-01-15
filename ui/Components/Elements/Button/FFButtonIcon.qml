import QtQuick

import Ui.Theme

FFButtonIconForm {
    id: root

    enum Type {
        Secundary,
        FlatPrimary,
        FlatSecundary
    }

    property int vType: FFButtonIcon.Type.Secundary

    // TODO migrate all of this routine to a button that inherit of FFButtonIcon, something as FFButtonNotification
    vHasNotification: root.vNotificationCount > 0

    onClicked: root._handleOnClicked()

    function _handleOnClicked() {
        root.vHasNotification = 0
    }

    function addNotificationCount(count) {
        root.vNotificationCount += count
    }

    function _handleOnNotificationCountChanged() {

        if (root.vNotificationCount > 9) {
            notificationCountLabel.text = "+9"
            return
        }

        notificationCountLabel.text = "%0".arg(root.vNotificationCount)
    }

    onVNotificationCountChanged: root._handleOnNotificationCountChanged()

    onVTypeChanged: root._setType()

    function _toSecundaryType() {
        root._color = Colors.secundary
        root._hoverColor = Colors.secundary
        root._colorIconHover = Colors.neutral100
        root._colorIcon = Colors.neutral100
        root._radius = Radius.sm
    }

    function toFlatSecundary() {
        root._color = "transparent"
        root._hoverColor = Colors.grey300
        root._colorIconHover = Colors.neutral100
        root._colorIcon = Colors.grey400
        root._radius = Radius.rounded
    }

    function toFlatPrimary() {
        root._color = "transparent"
        root._hoverColor = Colors.grey300
        root._colorIconHover = Colors.neutral100
        root._colorIcon = Colors.neutral100
        root._radius = Radius.rounded
    }

    function _setType() {
        switch (root.vType) {
        case FFButtonIcon.Type.Secundary:
            root._toSecundaryType()
            break
        case FFButtonIcon.Type.FlatPrimary:
            root.toFlatPrimary()
            break
        case FFButtonIcon.Type.FlatSecundary:
            root.toFlatSecundary()
            break
        }
    }

    Component.onCompleted: root._setType()
}
