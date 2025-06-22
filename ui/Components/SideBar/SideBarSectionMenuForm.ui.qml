pragma ComponentBehavior: Bound

import QtQuick
import QtQuick.Controls

import Ui.Theme

 Item {

    id: root

    height: column.height
    width: parent.width

    required property string vTitle
    required property ListModel vOptions

    property alias delegate: repeater.delegate

    property int _widthDelegate: columnRepeater._widthDelegate

    Column {

        id: column

        width: parent.width
        height: columnRepeater.height + menu.height
        spacing: Spacings.sm2

        Label {
            id: menu

            text: root.vTitle
            font: Fonts.caption160
            color: Colors.grey50
            leftPadding: Spacings.xl3
            rightPadding: Spacings.xl3
            bottomPadding: Spacings.sm2
        }

        Column {
            id: columnRepeater

            spacing: Spacings.sm2
            width: parent.width
            leftPadding: Spacings.md2
            rightPadding: Spacings.md2

            readonly property int _widthDelegate: parent.width - ( columnRepeater.leftPadding + columnRepeater.rightPadding )

            Repeater {
                id: repeater

                model: root.vOptions
            }
        }
    }
}
