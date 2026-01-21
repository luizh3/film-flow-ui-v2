import QtQuick
import QtQuick.Controls

import Ui.Theme

Row {
    spacing: Spacings.sm2

    property alias vText: labelText.text

    Rectangle {
        width: 5
        height: 32
        color: Colors.primary300
        radius: Radius.md
        anchors.verticalCenter: parent.verticalCenter
    }

    Label {
        id: labelText
        font: Fonts.title370
        color: Colors.grey50
        text: "Default"
        anchors.verticalCenter: parent.verticalCenter
    }
}
