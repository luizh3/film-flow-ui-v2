import QtQuick
import QtQuick.Controls

import Ui.Theme

Rectangle {
    height: 32
    width: childrenRect.width
    color: mouseArea.containsMouse ? Colors.grey300 : Colors.grey400
    radius: Radius.xl

    property alias mouseArea: mouseArea

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent
        cursorShape: Qt.PointingHandCursor
    }

    Row {
        spacing: Spacings.xs
        leftPadding: Spacings.sm2
        rightPadding: Spacings.sm2
        height: parent.height

        Label {
            color: Colors.grey50
            text: qsTr("Programs By")
            font: Fonts.label170
            anchors.verticalCenter: parent.verticalCenter
        }

        Image {
            id: sourceItem
            source: "qrc:/icons/tmdb"
            sourceSize: Qt.size(48, 24)
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
