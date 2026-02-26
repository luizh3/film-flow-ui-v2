import QtQuick

import Ui.Components.Elements

ThemePickerForm {

    id: root

    property var vModel
    property var vColorSelected

    colorsGridView.model: root.vModel

    function _handleOnColorSelected(index) {
        colorsGridView.model[index].isSelected = false
        colorsGridView.currentIndex = index
        root.vColorSelected = colorsGridView.model[index]
        root.vColorSelected.isSelected = true
    }

    Component.onCompleted: () => root._handleAdjustInitialSelected()

    function _handleAdjustInitialSelected() {
        root.colorsGridView.currentIndex = root.vModel.findIndex(
                    function (value) {
                        return value.isSelected
                    })
    }

    colorsGridView.delegate: FFColorItem {

        required property string color
        required property int index

        vColor: color
        vIsSelected: GridView.isCurrentItem
        onPressed: root._handleOnColorSelected(index)
    }
}
