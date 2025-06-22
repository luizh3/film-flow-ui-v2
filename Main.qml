pragma ComponentBehavior

import QtQuick
import QtQuick.Window
import QtQuick.Controls.Basic

import Ui.Screens

ApplicationWindow {
    id: application

    width: 1280
    height: 798
    visible: true
    title: qsTr("")
    flags: Qt.Window | Qt.FramelessWindowHint
    minimumWidth: 400
    minimumHeight: 400
    maximumWidth: Screen.desktopAvailableWidth * 2
    maximumHeight: Screen.desktopAvailableHeight * 2

    objectName: "Main"

    Component.onCompleted: {
        console.log("Pixel: " + Screen.pixelDensity)
    }

    property bool vIsFullscreen: application.visibility === Window.FullScreen

    ResizeManager {
        anchors.fill: parent
    }

    header: TitleBar {
        vIsFullscreen: application.vIsFullscreen
    }

    function _setScreen(screenComponent) {
        application.mainLoader.sourceComponent = screenComponent
    }

    Component {
        id: authComponent

        Auth {
            onSuccess: function () {
                application._setScreen(applicationScreenComponent)
            }
        }
    }

    Component {
        id: applicationScreenComponent

        ApplicationScreen {}
    }

    Loader {
        id: mainLoader
        anchors.fill: parent
        sourceComponent: applicationScreenComponent
    }
}
