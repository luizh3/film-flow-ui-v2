pragma ComponentBehavior

import QtQuick

FFComboBoxForm {
    id: root

    optionsList {
        model: root.vModel

        delegate: FFComboBoxForm.ItemComboDelegate {
            mouseArea.onClicked: root.vCurrentIndex = index
        }
    }

    function _handleCurrentIndexChanged() {
        root._currentImage = root.vModel[root.vCurrentIndex].vImage
        root._currentText = root.vModel[root.vCurrentIndex].vText
        root.optionsPopup.close()
    }

    function _handleComboSelectorPressed() {
        if (root._isPopupOpened) {
            root.optionsPopup.close()
            return
        }

        root.optionsPopup.open()
    }

    function _handleModelChanged() {
        root._handleAdjustInitialSelected()
    }

    function _handleAdjustInitialSelected() {
        root.vCurrentIndex = root.vModel.findIndex(function (value) {
            return value.vIsSelected
        })
    }

    Component.onCompleted: () => root._handleModelChanged()

    onVCurrentIndexChanged: () => root._handleCurrentIndexChanged()

    Connections {
        target: root.comboSelector.mouseArea

        function onClicked() {
            root._handleComboSelectorPressed()
        }
    }
}
