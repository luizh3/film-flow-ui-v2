import QtQuick

import Ui.Theme

Rectangle {
    id: root
    focus: true
    radius: Radius.xl
    color: Colors.grey500

    Component.onCompleted: {
        root.x = (parent.width - root.width) / 2
        root.y = (parent.height - root.height) / 2
    }

    signal close
}
