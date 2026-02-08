import QtQuick

import Ui.Components
import Controls 1.0

SettingsScreenForm {
    id: root

    function _handleInitialize(languages, colors) {
        root.vLanguagesModel = languages
        root.vColorsModel = colors
    }

    function _handleOnSave() {
        control.doSave(root.languageComboBox.vCurrentIndex,
                       themePicker.vColorSelected)
    }

    function _handleOnCompleted() {
        control.doStart()
    }

    Component.onCompleted: () => root._handleOnCompleted()

    saveButton.onClicked: () => root._handleOnSave()

    SettingsControl {
        id: control

        onInitialize: (languages, colors) => root._handleInitialize(languages,
                                                                    colors)
    }
}
