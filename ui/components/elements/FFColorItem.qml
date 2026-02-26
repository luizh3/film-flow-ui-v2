import QtQuick

FFColorItemForm {
    id: root

    signal pressed

    mouseArea.onClicked: root.pressed()
}
