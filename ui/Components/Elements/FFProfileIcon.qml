import QtQuick

import Ui.Theme

Rectangle {
    id: root
    implicitWidth: 32
    implicitHeight: 32
    radius: width / 2
    color: Colors.grey100

    required property string vIcon

    FFImageRounded {
        width: parent.width
        height: parent.height
        vRadius: parent.width / 2
        vMargin: 2
        vSource: root.vIcon
    }
}
