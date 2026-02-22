import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Control {
    id: root
    width: parent.width

    property int vOpacity: 1.0

    property alias searchTextField: searchTextField
    property alias notificationButton: notificationButton
    property alias profileOption: profileOption

    property string vUserImage: ""

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
            id: searchTextField
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
                vIcon: root.vUserImage
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
