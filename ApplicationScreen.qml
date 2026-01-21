import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import Ui.Theme
import Ui.Screens
import Ui.Components

import controls 1.0

Item {
    id: root
    implicitWidth: 1280
    implicitHeight: 768

    ApplicationControl {
        id: control
    }

    function _handleChangeItem(vType) {
        screenManager.clear()
        switch (vType) {
        case SideBar.TypeMenuItem.Home:
            loaderMainScreen.sourceComponent = homeComponent
            break
        case SideBar.TypeMenuItem.Favorites:
            loaderMainScreen.sourceComponent = favoritesComponent
            break
        case SideBar.TypeMenuItem.Reviews:
            loaderMainScreen.sourceComponent = reviewsComponent
            break
        case SideBar.TypeMenuItem.Movies:
            loaderMainScreen.sourceComponent = programsComponent
            break
        case SideBar.TypeMenuItem.Settings:
            loaderMainScreen.sourceComponent = settingsComponent
            break
        }
    }

    RowLayout {
        spacing: 0
        id: rowMainScreen
        anchors.fill: parent

        SideBar {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.maximumWidth: 350
            Layout.minimumWidth: 250
            onSelectedChanged: function (vType) {
                root._handleChangeItem(vType)
            }
        }

        Rectangle {
            Layout.preferredWidth: 1
            Layout.fillHeight: true
            color: Colors.grey500
        }

        Item {
            Layout.fillWidth: true
            Layout.fillHeight: true

            Loader {
                id: loaderMainScreen
                anchors.fill: parent
                visible: true
            }

            ScreenManager {
                id: screenManager
                anchors.fill: parent
            }
        }
    }

    Component {
        id: homeComponent

        HomeScreen {}
    }

    Component {
        id: settingsComponent

        SettingsScreen {}
    }

    Component {
        id: favoritesComponent

        Item {}
    }

    Component {
        id: programsComponent

        ProgramsScreen {}
    }

    Component {
        id: reviewsComponent

        ReviewScreen {}
    }

    Component.onCompleted: function () {
        control.doStart()
        root._handleChangeItem(SideBar.TypeMenuItem.Home)
    }
}
