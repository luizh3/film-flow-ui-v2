import QtQuick

import Ui.Components.Elements

Item {
    id: root

    function show(description, type) {

        const messageInformation = Qt.createQmlObject(`
                                                      import Ui.Components.Elements
                                                      FFToast {}
                                                      `, parent)

        messageInformation.vDescription = description
        messageInformation.state = type
    }

    function success(message) {
        root.show(message, FFToast.Types.SUCCESS)
    }

    function error(message) {
        root.show(message, FFToast.Types.ERROR)
    }

    function warning(message) {
        root.show(message, FFToast.Types.WARNING)
    }
}
