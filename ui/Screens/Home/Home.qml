import QtQuick
import controls 1.0

HomeForm {
    id: root

    function _handleSectionsChanged(sections) {
        console.log(sections)
        root.vSections = sections
    }

    HomeControl {
        id: control

        onSectionsChanged: sections => root._handleSectionsChanged(sections)
    }

    AuthControl {
        id: authControl
    }

    function _doStart() {
        authControl.configs()
        control.doStart()
    }

    Component.onCompleted: root._doStart()
}
