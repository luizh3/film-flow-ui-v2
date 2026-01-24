import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme
import Ui.Models

Popup {
    id: popup
    width: 600
    height: 300
    modal: false
    focus: false

    property alias listView: listView

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
                text: "Results founded"
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                visible: listView.visible
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
                visible: !listView.visible

                Label {
                    font: Fonts.body270
                    color: Colors.grey50
                    text: "No results founded"
                    anchors.centerIn: parent
                }
            }
            ListView {
                id: listView
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true
                spacing: 4
                visible: listView.count !== 0
                cacheBuffer: listView.height / 2

                model: SearchProgramListModel {
                    vDsQuery: popup.vDsQuery
                }

                ScrollBar.vertical: ScrollBar {}
            }
        }
    }
}
