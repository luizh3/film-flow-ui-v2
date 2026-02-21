import QtQuick
import QtQuick.Layouts

import Ui.Theme
import Ui.Components
import Ui.Components.Elements

import Presenter.Controls

GenericScreen {
    id: root

    implicitWidth: 1024
    implicitHeight: 768

    property var vUser

    property alias backButtonNavigation: backButtonNavigation
    property alias goBackButton: goBackButton

    property string vUserName: root.vUser?.name ?? ""
    property string vUserEmail: root.vUser?.email ?? ""
    property string vUserImage: root.vUser?.avatarUrl
                                || "qrc:/imagens/no-user.png"

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
                id: ffProfileIcon
                Layout.preferredWidth: 150
                Layout.preferredHeight: 150
                vHasHover: false
                Layout.alignment: Qt.AlignHCenter
                vIcon: root.vUserImage

                FFSkeletonLoading {
                    id: skeletonLoading
                    anchors.fill: parent
                    color: Colors.grey600
                    radius: parent.radius
                    opacity: ffProfileIcon.vIsReady ? 0 : 1
                    vOpacityDuration: Durations.normal
                }
            }

            FFTextField {
                id: nameField
                Layout.fillWidth: true
                vLabel: qsTr("Name")
                vText: root.vUserName
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
                vText: root.vUserEmail
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
                    vIconColor: Colors.orange300
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
