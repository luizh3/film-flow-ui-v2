import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

import core 1.0

Rectangle {
    id: root
    implicitHeight: 720
    implicitWidth: 636
    color: Colors.grey600

    property alias mouseAreaSignUp: mouseAreaSignUp
    property alias loginButton: loginButton

    property alias passwordField: passwordField
    property alias emailField: emailField

    ColumnLayout {
        width: parent.width
        anchors.leftMargin: Spacings.xl3
        anchors.rightMargin: Spacings.xl3
        anchors.left: parent.left
        anchors.right: parent.right
        spacing: Spacings.md
        anchors.verticalCenter: parent.verticalCenter

        FFLogo {
            id: logo
            vFont: Fonts.title170
            Layout.alignment: Qt.AlignHCenter
        }

        ColumnLayout {
            id: columnContent
            Layout.fillWidth: true

            spacing: Spacings.xl3

            FFTextField {
                id: emailField
                Layout.fillWidth: true
                vLabel: qsTr("E-mail")
                vPlaceHolderText: ""
                vValidator: EmailValidator {}
            }

            FFPasswordTextField {
                id: passwordField
                Layout.fillWidth: true
                vValidator: RangeValidator {
                    vMin: 8
                    vMax: 20
                }
            }

            FFButton {
                id: loginButton
                Layout.fillWidth: true
                text: qsTr("Login")
                vIcon: Icons.outlined.check
            }

            Row {
                spacing: Spacings.sm
                Layout.alignment: Qt.AlignHCenter

                Label {
                    font: Fonts.caption150
                    color: Colors.grey50
                    text: qsTr("Don’t have account ?")
                    opacity: !enabled ? 0.5 : 1
                }

                Label {
                    font: Fonts.caption170
                    color: Colors.primary500
                    opacity: !enabled ? 0.5 : mouseAreaSignUp.containsMouse ? 0.8 : 1
                    text: qsTr("Sign Up")

                    MouseArea {
                        id: mouseAreaSignUp
                        anchors.fill: parent
                        hoverEnabled: true
                    }
                }
            }
        }
    }
}
