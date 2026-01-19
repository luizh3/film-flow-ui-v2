import QtQuick

FFButtonReactionForm {
    id: root

    signal selected(var isSelected)

    function doDeselected() {
        root.vIsSelected = false
        root.vLikesCount = Math.max(root.vLikesCount - 1, 0)
    }

    function doSelected() {
        root.vIsSelected = true
        root.vLikesCount = root.vLikesCount + 1
    }

    function _handleOnSelected() {

        if (root.vIsSelected) {
            root.doDeselected()
        } else {
            root.doSelected()
        }

        root.selected(root.vIsSelected)
    }

    mouseArea.onClicked: () => root._handleOnSelected()
}
