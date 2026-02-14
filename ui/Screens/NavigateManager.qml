pragma Singleton

import QtQuick

QtObject {
    id: root

    property ScreenManager vScreenManager
    property PopupManager vPopupManager

    function navigateScreen(tpRoute, props = {}) {
        if (!root.vScreenManager) {
            return
        }
        return root.vScreenManager.navigate(tpRoute, props)
    }

    function navigatePopup(popup, props = {}) {
        if (!vPopupManager) {
            return
        }
        return vPopupManager.push(popup, props)
    }
}
