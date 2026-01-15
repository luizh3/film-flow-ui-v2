import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements
import Ui.Components

Control {
    id: root
    width: parent.width

    property int vOpacity: 1.0
    property bool vIsUsingSearchPopup: true

    property alias searchProgramTextField: searchProgramTextField
    property alias notificationButton: notificationButton
    property alias profileOption: profileOption

    background: Item {
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
            color: Colors.grey600
            opacity: root.vOpacity

            Behavior on opacity {
                NumberAnimation {
                    duration: Durations.normal
                }
            }
        }
    }

    contentItem: RowLayout {
        spacing: 0

        FFTextField {
            id: searchProgramTextField
            Layout.fillWidth: true
            Layout.minimumWidth: 172
            Layout.maximumWidth: 424
            vIconLeft: "qrc:/icons/search"
            vIconRight: "qrc:/icons/filter"
            vPlaceHolderText: qsTr("Search for a movie")
            Layout.alignment: Qt.AlignLeft
            vType: FFTextField.Type.Secundary
        }

        Row {
            Layout.alignment: Qt.AlignRight
            spacing: Spacings.md

            FFButtonIcon {
                id: notificationButton
                vIcon: "qrc:/icons/notification"
                vType: FFButtonIcon.Type.FlatPrimary
                anchors.verticalCenter: parent.verticalCenter
                ToolTip.text: qsTr("Notifications")
            }

            FFProfileIcon {
                id: profileOption
                vIcon: "https://swordslice.com/cdn/shop/articles/jjk-does-nanami-die.webp?v=1752508661&width=1100"
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
