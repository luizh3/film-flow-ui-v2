import QtQuick
import QtQuick.Controls

import Ui.Theme

ToolTip {
    text: ""
    palette.toolTipText: Colors.grey50
    font: Fonts.label170
    background: Rectangle {
        color: Colors.grey700
        radius: Radius.xl
    }
}
