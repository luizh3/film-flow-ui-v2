import QtQuick
import QtQuick.Controls

import Ui.Theme

import "../LoadingCircle"

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

    background: Rectangle {
        opacity: root.hovered && root.enabled ? 0.8 : 1
        radius: Radius.md

        Behavior on opacity {
            NumberAnimation {
                duration: 150
                easing.type: Easing.InOutQuad
            }
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
