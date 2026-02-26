import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme

ColumnLayout {
    id: root
    spacing: Spacings.sm

    implicitWidth: 424
    implicitHeight: 200

    property string vLabel: ""

    property int vType: FFTextField.Type.Primary

    property alias vPlaceHolderText: textArea.placeholderText
    property alias vText: textArea.text

    property alias label: label
    property alias background: background
    property alias textArea: textArea

    Label {
        id: label
        font: Fonts.caption270
        Layout.fillWidth: true
        color: Colors.neutral100
    }

    Rectangle {
        id: background
        Layout.fillWidth: true
        Layout.fillHeight: true
        border.width: 2
        radius: Radius.md
        color: Colors.grey700
        border.color: Colors.grey400

        RowLayout {
            spacing: 0
            anchors.fill: parent

            TextArea {
                id: textArea

                Layout.fillWidth: true
                Layout.fillHeight: true

                placeholderText: qsTr("Placeholder...")

                font: Fonts.caption250
                color: Colors.neutral100
                selectionColor: Colors.grey300
                placeholderTextColor: Colors.grey200
                selectedTextColor: Colors.neutral100

                background: Item {}

                Layout.margins: Spacings.md
            }
        }
    }
}
