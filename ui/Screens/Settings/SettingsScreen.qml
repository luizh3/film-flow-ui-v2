import QtQuick

import Ui.Components
import controls 1.0

SettingsScreenForm {
    id: root

    function _handleInitialize(languages) {
        root.vModel = languages
    }

    SettingsControl {
        id: control

        onInitialize: languages => root._handleInitialize(languages)
    }

    Component.onCompleted: function () {
        control.doStart()
    }

    function _handleOnSave() {
        control.doSave(root.languageComboBox.vCurrentIndex)
    }

    saveButton.onClicked: () => root._handleOnSave()
}
