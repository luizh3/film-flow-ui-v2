import QtQuick
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Button {

    id: root
    implicitHeight: 50
    icon.width: 18
    icon.height: 18
    spacing: Spacings.sm2
    font: Fonts.caption260
    palette.buttonText: Colors.neutral100
    leftPadding: Spacings.xl3
    rightPadding: Spacings.xl3

    property alias loading: loading

    property string vColorBackground: ""
    property bool _hasTabFocus: root.activeFocus

    background: Item {

        Rectangle {
            id: backgroundRectangle
            width: root.width
            height: root.height
            opacity: root.hovered && root.enabled ? 0.8 : 1
            radius: Radius.md
            color: root.vColorBackground

            // TODO move this for .qml
            Behavior on opacity {
                NumberAnimation {
                    duration: Durations.normal
                    easing.type: Easing.InOutQuad
                }
            }
        }

        Rectangle {
            color: Colors.transparent
            border.width: 1
            border.color: Colors.focus
            radius: Radius.md
            width: backgroundRectangle.width + Spacings.sm
            height: backgroundRectangle.height + Spacings.sm
            anchors.centerIn: parent
            visible: root._hasTabFocus
        }
    }

    FFLoadingCircle {
        id: loading
        anchors.fill: parent
        anchors.centerIn: parent
        visible: false
        size: 30
        lineWidth: 3
    }
}
