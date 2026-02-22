import QtQuick
import QtQuick.Layouts

import Ui.Theme
import Ui.Screens
import Ui.Components
import Ui.Components.Elements

import Presenter.Controls

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
            loaderMainScreen.changeSource(homeComponent, Durations.instant)
            break
        case SideBar.TypeMenuItem.Favorites:
            loaderMainScreen.changeSource(favoritesComponent, Durations.slow)
            break
        case SideBar.TypeMenuItem.Reviews:
            loaderMainScreen.changeSource(reviewsComponent, Durations.slow)
            break
        case SideBar.TypeMenuItem.Movies:
            loaderMainScreen.changeSource(programsComponent, Durations.slow)
            break
        case SideBar.TypeMenuItem.Settings:
            loaderMainScreen.changeSource(settingsComponent, Durations.slow)
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

            Rectangle {
                color: Colors.grey500
                anchors.fill: parent

                FFLoader {
                    id: loaderMainScreen
                    anchors.fill: parent
                    visible: true
                }
            }

            // TODO change this to has a singleton connections.
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
        NavigateManager.vScreenManager = screenManager
        control.doStart()
        root._handleChangeItem(SideBar.TypeMenuItem.Home)
    }
}
