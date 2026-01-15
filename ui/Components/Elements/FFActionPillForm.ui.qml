import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Rectangle {
    id: root

    width: 230
    height: 65
    color: Colors.grey700
    radius: Radius.sm

    required property string vText
    required property string vIcon
    required property string vBagdetText
    required property string vIconColor

    RowLayout {
        anchors.fill: parent
        anchors.leftMargin: Spacings.lg
        anchors.rightMargin: Spacings.lg

        RowLayout {
            Layout.fillWidth: true
            spacing: Spacings.md

            FFIcon {
                source: root.vIcon
                sourceSize: Qt.size(24, 24)
                vColor: root.vIconColor
                Layout.alignment: Qt.AlignVCenter
            }

            Label {
                font: Fonts.caption270
                text: root.vText
                color: Colors.grey50
            }
        }

        FFBadget {
            vText: root.vBagdetText
            Layout.alignment: Qt.AlignRight
        }
    }
}
