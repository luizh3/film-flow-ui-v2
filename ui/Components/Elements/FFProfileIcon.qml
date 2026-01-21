import QtQuick

import Ui.Theme

Rectangle {
    id: root
    implicitWidth: 32
    implicitHeight: 32
    radius: width / 2
    color: mouseArea.containsMouse
           && root.vHasHover ? Colors.primary500 : Colors.grey100

    property bool vHasHover: true
    required property string vIcon

    signal selected

    FFToolTip {
        visible: mouseArea.containsMouse && root.vHasHover
        text: qsTr("Profile")
    }

    MouseArea {
        id: mouseArea
        hoverEnabled: true
        anchors.fill: parent
        onClicked: root.selected()
    }

    FFImageRounded {
        width: parent.width
        height: parent.height
        vRadius: parent.width / 2
        vMargin: 2
        vSource: root.vIcon
    }
}
