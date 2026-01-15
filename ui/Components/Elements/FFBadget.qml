import QtQuick
import QtQuick.Controls

import Ui.Theme

Rectangle {
    id: root
    color: Colors.primary
    implicitHeight: 33
    width: labelText.width + _nrSideMargin * 2
    radius: Radius.md

    property int _nrSideMargin: 12
    property alias vText: labelText.text

    Label {
        id: labelText
        color: Colors.grey50
        font: Fonts.caption270
        text: "Default"
        anchors.centerIn: parent
    }
}
