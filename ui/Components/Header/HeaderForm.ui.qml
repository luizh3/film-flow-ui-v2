import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Components.Elements

Control {
    id: root
    width: parent.width

    property int vOpacity: 1.0

    background: Item {
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent
            color: Colors.grey600
            opacity: root.vOpacity

            Behavior on opacity {
                NumberAnimation {
                    duration: 150
                }
            }
        }
    }

    contentItem: RowLayout {
        spacing: 0

        FFTextField {
            id: textField
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
                vIcon: "qrc:/icons/notification"
                vType: FFButtonIcon.Type.FlatPrimary
                vHasNotification: true
                anchors.verticalCenter: parent.verticalCenter
                ToolTip.text: qsTr( "Notifications" )
            }

            FFProfileIcon {
                vIcon: "https://static.wikia.nocookie.net/inazumajet/images/0/0d/Arbafika.jpg/revision/latest?cb=20110816230950&path-prefix=pt-br"
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
