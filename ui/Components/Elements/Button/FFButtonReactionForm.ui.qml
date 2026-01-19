import QtQuick
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Rectangle {
    id: root
    width: childrenRect.width
    border.color: Colors.grey100
    height: 36
    border.width: 1
    color: mouseArea.containsMouse ? Colors.grey400 : Colors.transparent
    radius: Radius.md

    Behavior on color {
        ColorAnimation {
            duration: Durations.fast
        }
    }

    required property string vIcon
    required property string vIconSelected
    required property string vIconColor

    required property int vLikesCount

    property bool vIsSelected: false

    property alias mouseArea: mouseArea

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
    }

    Row {
        height: parent.height
        spacing: 8
        leftPadding: 12
        rightPadding: 12

        FFIcon {
            source: root.vIsSelected ? root.vIconSelected : root.vIcon
            sourceSize: Qt.size(14, 14)
            vColor: root.vIconColor
            anchors.verticalCenter: parent.verticalCenter
        }

        Label {
            font: Fonts.label140
            text: root.vLikesCount
            color: Colors.grey50
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
