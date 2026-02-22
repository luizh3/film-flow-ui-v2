import QtQuick

Loader {
    id: root

    function changeSource(element, duration = 0) {
        itemFadeIn.stop()
        itemFadeIn.target = null
        itemFadeIn.duration = duration
        root.sourceComponent = element
    }

    function _handleOnLoaded() {

        if (!root.item || !(itemFadeIn.duration > 0)) {
            return
        }

        root.item.opacity = 0
        itemFadeIn.target = root.item
        itemFadeIn.start()
    }

    onLoaded: root._handleOnLoaded()

    NumberAnimation {
        id: itemFadeIn
        property: "opacity"
        from: 0
        to: 1
        duration: 0
        easing.type: Easing.OutCubic
    }
}
