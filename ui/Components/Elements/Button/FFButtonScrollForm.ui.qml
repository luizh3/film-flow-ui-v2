import QtQuick
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Rectangle {
    radius: Radius.sm
    border.color: Colors.grey400
    width: content.implicitWidth
    height: content.implicitHeight

    property alias handlerMouse: handlerMouse

    Behavior on color {
        ColorAnimation {
            duration: Durations.normal
        }
    }

    Row {
        id: content
        spacing: Spacings.xs
        padding: Spacings.sm

        FFIcon {
            source: Icons.outlined.upArrow
            sourceSize: Qt.size(24, 24)
            vColor: Colors.grey50
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            font: Fonts.label140
            color: Colors.grey50
            text: qsTr("To Top")
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    MouseArea {
        id: handlerMouse
        anchors.fill: parent
        hoverEnabled: true
    }
}
