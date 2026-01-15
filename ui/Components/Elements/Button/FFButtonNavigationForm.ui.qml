import QtQuick
import QtQuick.Controls

import Ui.Theme

Row {
    id: root
    width: parent.width
    spacing: Spacings.sm2

    property string vText: "Default"
    property string vIcon: Icons.outlined.leftArrow
    property string vHoverText: "Default"

    property alias buttonIcon: buttonIcon

    FFButtonIcon {
        id: buttonIcon
        vIcon: root.vIcon
        ToolTip.text: root.vHoverText
    }

    Label {
        font: Fonts.body270
        text: "/ " + root.vText
        color: Colors.grey50
        anchors.verticalCenter: parent.verticalCenter
    }
}
