pragma ComponentBehavior

import QtQuick
import Ui.Theme
import QtQuick.Layouts
import QtQuick.Controls

Rectangle {
    id: root
    height: 40
    width: row.width + (Spacings.sm * 2)
    radius: Radius.sm
    color: Colors.grey600

    property alias badgetScore: badgetScore
    property alias listView: listView

    property int vNrRating: 10
    property int vCurrentValue: listView.currentIndex + 1

    RowLayout {
        id: row
        height: parent.height
        spacing: Spacings.sm2
        anchors.horizontalCenter: parent.horizontalCenter

        ListView {
            id: listView
            model: root.vNrRating
            Layout.preferredWidth: listView.childrenRect.width
            spacing: Spacings.sm
            orientation: ListView.Horizontal
            Layout.preferredHeight: 24
            currentIndex: -1
            Layout.alignment: Qt.AlignVCenter
        }

        Rectangle {
            id: badgetScore
            Layout.preferredWidth: label.width + 24
            Layout.preferredHeight: 28
            radius: Radius.sm

            Label {
                id: label
                text: "%0 out of 10".arg(root.vCurrentValue)
                font: Fonts.label170
                color: Colors.grey50
                anchors.centerIn: parent
            }
        }
    }
}
