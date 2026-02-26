import QtQuick

import Ui.Components.Elements

Item {

    anchors.left: parent.left
    anchors.right: parent.right
    anchors.bottom: parent.bottom
    height: 50
    property alias buttonScroll: buttonScroll

    FFButtonScroll {
        id: buttonScroll
        anchors.centerIn: parent
    }
}
