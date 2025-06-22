import QtQuick
import QtQuick.Controls

import Ui.Theme

Row {
    id: headerRow
    width: parent.width
    anchors.top: parent.top
    anchors.left: parent.left
    anchors.topMargin: 32
    anchors.leftMargin: 32
    spacing: Spacings.sm2

    FFButtonIcon {
        id: backButton
        vIcon: "qrc:/icons/left-arrow"
        ToolTip.text: qsTr("Go back to login")
    }

    Label {
        font: Fonts.body270
        text: qsTr("/ Sign Up")
        color: Colors.grey50
        anchors.verticalCenter: parent.verticalCenter
    }
}
