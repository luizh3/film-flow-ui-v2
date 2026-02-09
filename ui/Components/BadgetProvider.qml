import QtQuick

import Ui.Theme

BadgetProviderForm {

    // TODO change this to be generic when has more than one provider
    mouseArea.onClicked: Qt.openUrlExternally("https://www.themoviedb.org")

    Behavior on color {
        ColorAnimation {
            duration: Durations.normal
        }
    }
}
