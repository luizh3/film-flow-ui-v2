pragma ComponentBehavior: Bound

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

    readonly property alias _menusView : _menusView
    property int vTypeSelected: SideBar.TypeMenuItem.Home

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
    }
}
