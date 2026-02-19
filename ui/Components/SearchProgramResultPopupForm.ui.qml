import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme

Popup {
    id: root
    width: 600
    height: 300
    modal: false
    focus: false

    property alias moviesList: moviesList

    property string vDsQuery: ""

    background: Rectangle {
        color: Colors.grey700
        radius: 4

        ColumnLayout {
            anchors.fill: parent
            anchors.margins: Spacings.md2
            spacing: 6

            Label {
                id: label
                font: Fonts.caption270
                color: Colors.grey50
                text: qsTr("Results founded")
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                visible: moviesList.visible
            }

            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 1
                color: Colors.grey500
            }

            Item {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignCenter
                visible: !moviesList.visible

                Label {
                    font: Fonts.body270
                    color: Colors.grey50
                    text: qsTr("No results founded")
                    anchors.centerIn: parent
                }
            }
            ListView {
                id: moviesList
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true
                spacing: 4
                visible: moviesList.count !== 0
                cacheBuffer: moviesList.height / 2

                ScrollBar.vertical: ScrollBar {}
            }
        }
    }
}
