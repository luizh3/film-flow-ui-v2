import QtQuick

import Ui.Theme

Item {
    id: root
    width: 36
    height: 36

    property string vColor
    property bool vIsSelected: false

    property alias mouseArea: mouseArea

    Rectangle {
        anchors.fill: parent
        radius: 360
        color: root.vColor
        border.color: root.vIsSelected ? Colors.neutral100 : Colors.transparent
        border.width: 2
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
    }
}
