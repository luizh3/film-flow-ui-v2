import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme
import Ui.Components
import Ui.Components.Elements

Rectangle {
    id: root

    implicitWidth: 1024
    implicitHeight: 768

    color: Colors.grey500

    property var vLanguagesModel: []
    property var vColorsModel: []

    property alias saveButton: saveButton
    property alias languageComboBox: languageComboBox
    property alias themePicker: themePicker

    Item {
        anchors.fill: parent
        anchors.margins: Spacings.xl3

        Item {
            height: parent.height
            width: Math.min(parent.width, 1024)
            anchors.horizontalCenter: parent.horizontalCenter

            Column {
                width: parent.width
                height: parent.height
                spacing: Spacings.xl3
                anchors.horizontalCenter: parent.horizontalCenter

                Label {
                    text: qsTr("Settings")
                    color: Colors.grey50
                    font: Fonts.title370
                }

                ColumnLayout {
                    width: parent.width
                    spacing: Spacings.md

                    ColumnLayout {
                        width: parent.width
                        spacing: Spacings.md

                        Label {
                            text: qsTr("Select language")
                            color: Colors.grey50
                            font: Fonts.caption240
                        }

                        FFComboBox {
                            id: languageComboBox
                            vModel: root.vLanguagesModel
                        }
                    }

                    ColumnLayout {
                        width: parent.width
                        spacing: Spacings.md

                        Label {
                            text: qsTr("Select Primary Color")
                            color: Colors.grey50
                            font: Fonts.caption240
                        }

                        ThemePicker {
                            id: themePicker
                            vModel: root.vColorsModel
                        }
                    }
                }
            }

            FFButton {
                id: saveButton
                width: parent.width
                text: qsTr("Save")
                vIcon: Icons.outlined.check
                anchors.bottom: parent.bottom
            }
        }
    }
}
