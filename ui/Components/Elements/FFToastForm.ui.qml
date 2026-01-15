import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme

Rectangle {
    id: root
    width: 350
    height: 48
    color: Colors.grey500
    radius: Radius.md

    property alias icon: icon

    property string vDescription
    property alias closeButton: closeButton

    FFIcon {
        id: icon
        vColor: Colors.neutral100
        sourceSize: Qt.size(18, 18)
        anchors.verticalCenter: parent.verticalCenter
        anchors.left: parent.left
        anchors.leftMargin: Spacings.md
    }

    ColumnLayout {
        anchors.left: icon.right
        anchors.leftMargin: Spacings.md
        anchors.right: closeButton.left
        anchors.rightMargin: Spacings.md
        anchors.verticalCenter: parent.verticalCenter
        width: parent.width

        Label {
            font: Fonts.caption250
            Layout.fillWidth: true
            wrapMode: Text.WordWrap
            color: Colors.neutral100
            text: root.vDescription
        }
    }

    Button {
        id: closeButton
        anchors.right: parent.right
        anchors.rightMargin: Spacings.sm
        anchors.verticalCenter: parent.verticalCenter
        icon.source: "qrc:/icons/close"
        icon.color: Colors.neutral100
        background: Rectangle {
            color: "transparent"
        }
    }
}
