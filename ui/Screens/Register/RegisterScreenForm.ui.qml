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

    property alias backButton: backButton

    property alias passwordField: passwordField
    property alias passwordRepeatField: passwordRepeatField
    property alias nameField: nameField
    property alias emailField: emailField
    property alias signUpButton: signUpButton

    Row {
        id: headerRow
        width: parent.width
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.topMargin: 32
        anchors.leftMargin: 32
        spacing: Spacings.sm2

        FFButtonIcon {
            id: backButton
            vIcon: Icons.outlined.leftArrow
            ToolTip.text: qsTr("Go back to login")
        }

        Label {
            font: Fonts.body270
            text: qsTr("/ Sign Up")
            color: Colors.grey50
            anchors.verticalCenter: parent.verticalCenter
        }
    }

    property int _heightWihoutHeader: root.height - (headerRow.height + headerRow.anchors.topMargin)

    ScrollView {
        width: parent.width
        height: root._heightWihoutHeader
        contentWidth: parent.width
        contentHeight: itemColumn.height
        anchors.top: headerRow.bottom

        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Item {
            id: itemColumn
            anchors.leftMargin: Spacings.xl3
            anchors.rightMargin: Spacings.xl3
            anchors.bottomMargin: Spacings.md
            anchors.left: parent.left
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            width: root.width
            height: Math.max(root._heightWihoutHeader, column.height)

            ColumnLayout {
                id: column
                anchors.verticalCenter: parent.verticalCenter
                spacing: Spacings.md
                width: parent.width

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
                        id: nameField
                        Layout.fillWidth: true
                        vLabel: qsTr("Name")
                        vPlaceHolderText: ""
                        vValidator: RangeValidator {
                            vMin: 3
                            vMax: 30
                        }
                    }

                    FFTextField {
                        id: emailField
                        Layout.fillWidth: true
                        vLabel: qsTr("E-mail")
                        vPlaceHolderText: ""
                        vValidator: EmailValidator {}
                    }

                    RowLayout {
                        Layout.fillWidth: true
                        spacing: Spacings.lg

                        FFPasswordTextField {
                            id: passwordField
                            Layout.alignment: Qt.AlignTop
                            Layout.fillWidth: true
                            vValidator: PasswordValidator {}
                        }

                        FFPasswordTextField {
                            id: passwordRepeatField
                            Layout.alignment: Qt.AlignTop
                            Layout.fillWidth: true
                            vLabel: qsTr("Repeat password")
                            vValidator: PasswordValidator {
                                vTypeValidation: PasswordValidator.REPEAT
                                vRepeatPassword: passwordField.vText
                            }
                        }
                    }

                    FFButton {
                        id: signUpButton
                        Layout.fillWidth: true
                        text: qsTr("Register")
                        vIcon: Icons.outlined.check
                    }
                }
            }
        }
    }
}
