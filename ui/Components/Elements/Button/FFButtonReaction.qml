import QtQuick

FFButtonReactionForm {
    id: root

    function _handleOnSelected() {
        root.vIsSelected = !root.vIsSelected
    }

    mouseArea.onClicked: () => root._handleOnSelected()
}
