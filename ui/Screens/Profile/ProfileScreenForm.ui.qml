import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components
import Ui.Components.Elements

import core 1.0

GenericScreen {
    id: root

    implicitWidth: 1024
    implicitHeight: 768

    property var vUser

    property alias backButtonNavigation: backButtonNavigation
    property alias goBackButton: goBackButton

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: Spacings.xl

        FFButtonNavigation {
            id: backButtonNavigation
            vText: qsTr("Profile")
            vHoverText: qsTr("Profile")
        }

        ColumnLayout {
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: Spacings.xl2
            Layout.maximumWidth: 1024
            Layout.alignment: Qt.AlignHCenter

            FFProfileIcon {
                Layout.preferredWidth: 150
                Layout.preferredHeight: 150
                vHasHover: false
                Layout.alignment: Qt.AlignHCenter
                vIcon: "https://swordslice.com/cdn/shop/articles/jjk-does-nanami-die.webp?v=1752508661&width=1100"
            }

            FFTextField {
                id: nameField
                Layout.fillWidth: true
                vLabel: qsTr("Name")
                vText: vUser?.name ?? ""
                vType: FFTextField.Type.Primary
                enabled: false
                vValidator: RangeValidator {
                    vMin: 3
                    vMax: 30
                }
            }

            FFTextField {
                id: emailField
                Layout.fillWidth: true
                vLabel: qsTr("E-mail")
                vText: vUser?.email ?? ""
                enabled: false
                vValidator: EmailValidator {}
            }

            RowLayout {
                Layout.fillWidth: true
                spacing: Spacings.xl

                FFActionPill {
                    vIcon: Icons.outlined.star
                    vText: qsTr("Reviews")
                    vBagdetText: "23"
                    vIconColor: Colors.primary300
                }

                FFActionPill {
                    vIcon: Icons.outlined.favorite
                    vText: qsTr("Favorites")
                    vBagdetText: "23"
                    vIconColor: Colors.red400
                }
            }
        }

        RowLayout {
            Layout.fillWidth: true
            spacing: Spacings.xl
            Layout.maximumWidth: 1024
            Layout.alignment: Qt.AlignHCenter

            FFButton {
                id: goBackButton
                Layout.fillWidth: true
                text: qsTr("Go back")
                vIcon: Icons.outlined.leftArrow
                vType: FFButton.Type.Secundary
            }

            FFButton {
                id: saveButton
                Layout.fillWidth: true
                text: qsTr("Save")
                vIcon: Icons.outlined.check
            }
        }
    }
}
