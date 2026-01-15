ProfileScreenForm {
    id: root

    function _handleClose() {
        root.close()
    }

    backButtonNavigation.onClicked: root._handleClose()
    goBackButton.onClicked: root._handleClose()
}
