pragma Singleton

import QtQuick

QtObject {
    id: root

    property ScreenManager vScreenManager
    property ModalManager vModalManager
    property PopupManager vPopupManager

    function navigateScreen(tpRoute, props = {}) {
        if (!root.vScreenManager) {
            return
        }
        return root.vScreenManager.navigate(tpRoute, props)
    }

    function navigateModal(modal, props = {}) {
        if (!root.vModalManager) {
            return
        }
        return root.vModalManager.push(modal, props)
    }

    function openPopup(type, positionerElement, setupCallback) {
        if (!root.vPopupManager) {
            return
        }
        return root.vPopupManager.open(type, positionerElement, setupCallback)
    }
}
