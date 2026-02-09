import QtQuick

import Ui.Theme

FFButtonScrollForm {
    id: root

    signal pressed

    color: handlerMouse.containsMouse ? Colors.grey700 : Colors.grey800

    handlerMouse.onClicked: root.pressed()

    Behavior on color {
        ColorAnimation {
            duration: Durations.normal
        }
    }
}
