import QtQuick

import Ui.Components
import controls 1.0

SettingsScreenForm {
    id: root

    function _handleInitialize(languages, colors) {
        root.vLanguagesModel = languages
        root.vColorsModel = colors
    }

    SettingsControl {
        id: control

        onInitialize: (languages, colors) => root._handleInitialize(languages,
                                                                    colors)
    }

    Component.onCompleted: function () {
        control.doStart()
    }

    function _handleOnSave() {
        control.doSave(root.languageComboBox.vCurrentIndex,
                       themePicker.vColorSelected)
    }

    saveButton.onClicked: () => root._handleOnSave()
}
