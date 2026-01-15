pragma ComponentBehavior

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import Ui.Theme
import Ui.Components.Elements

Rectangle {
    id: root

    implicitWidth: 280
    implicitHeight: 768
    color: Colors.grey600

    readonly property alias _menusView: _menusView
    property int vTypeSelected: SideBar.TypeMenuItem.Home

    component BadgetProvider: Rectangle {
        height: 32
        width: childrenRect.width
        color: mouseArea.containsMouse ? Colors.grey300 : Colors.grey400
        radius: Radius.xl

        MouseArea {
            id: mouseArea
            hoverEnabled: true
            anchors.fill: parent

            onClicked: {
                Qt.openUrlExternally("https://www.themoviedb.org")
            }
        }

        Behavior on color {
            ColorAnimation {
                duration: Durations.normal
            }
        }

        Row {
            spacing: Spacings.xs
            leftPadding: Spacings.sm2
            rightPadding: Spacings.sm2
            height: parent.height

            Label {
                color: Colors.grey50
                text: qsTr("Programs By")
                font: Fonts.label170
                anchors.verticalCenter: parent.verticalCenter
            }

            Image {
                id: sourceItem
                source: "qrc:/icons/tmdb"
                sourceSize: Qt.size(48, 24)
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }

    ColumnLayout {
        anchors.fill: parent
        spacing: Spacings.lg
        anchors.topMargin: Spacings.xl4

        FFLogo {
            Layout.fillWidth: true
            leftPadding: Spacings.xl3
        }

        ListView {
            id: _menusView
            Layout.fillWidth: true
            Layout.fillHeight: true
            spacing: Spacings.lg
            clip: true

            ScrollBar.vertical: ScrollBar {}
        }

        BadgetProvider {
            Layout.leftMargin: Spacings.xl3
            Layout.bottomMargin: Spacings.xl3
        }
    }
}
