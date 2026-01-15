import Ui.Theme

FFButtonScrollForm {
    id: root

    signal pressed

    color: handlerMouse.containsMouse ? Colors.grey700 : Colors.grey800

    handlerMouse.onClicked: root.pressed()
}
