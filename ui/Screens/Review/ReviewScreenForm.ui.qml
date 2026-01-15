import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components

Rectangle {

    implicitWidth: 1024
    implicitHeight: 768

    color: Colors.grey500

    property alias header: header
    property alias reviewsList: reviewsList

    property alias foundResultsLabel: foundResultsLabel

    ColumnLayout {
        anchors.fill: parent

        Header {
            id: header
            Layout.fillWidth: true
            rightPadding: Spacings.xl3
            leftPadding: Spacings.xl3
            bottomPadding: Spacings.xl2
            topPadding: Spacings.xl2
            vOpacity: 0.0
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: Spacings.md

            RowLayout {
                Layout.fillWidth: true
                Layout.leftMargin: Spacings.xl3
                Layout.rightMargin: Spacings.xl3

                Label {
                    font: Fonts.caption170
                    color: Colors.grey50
                    text: qsTr("Your reviews")
                    Layout.fillWidth: true
                }

                Label {
                    id: foundResultsLabel
                    font: Fonts.caption250
                    color: Colors.grey50
                }
            }

            ListView {
                id: reviewsList
                Layout.fillWidth: true
                Layout.fillHeight: true
                clip: true
                spacing: Spacings.md
                visible: true

                footer: Item {
                    height: Spacings.xl3
                }

                ScrollBar.vertical: ScrollBar {}
            }
        }
    }
}
