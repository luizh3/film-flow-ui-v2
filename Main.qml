pragma ComponentBehavior

import QtQuick
import QtQuick.Window
import QtQuick.Controls.Basic

import Ui.Screens
import Ui.Components

import controls 1.0

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

    property bool vIsFullscreen: application.visibility === Window.FullScreen

    ResizeManager {
        anchors.fill: parent
    }

    header: TitleBar {
        vIsFullscreen: application.vIsFullscreen
    }

    function _setScreen(screenComponent) {
        mainLoader.sourceComponent = screenComponent
    }

    Component {
        id: authComponent

        AuthScreen {
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

    PopupManager {
        id: popupManager
        width: parent.width
        height: parent.height
        anchors.bottom: parent.bottom
    }

    ToastManager {
        id: toastManager
    }

    MainControl {
        onNotifierToastWarning: message => toastManager.warning(message)
        onNotifierToastSuccess: message => toastManager.success(message)
        onNotifierToastError: message => toastManager.error(message)
    }
}
