pragma ComponentBehavior

import QtQuick

import controls 1.0

SideBarForm {
    id: root

    objectName: "SideBar"

    signal selectedChanged(int vType)

    enum TypeMenuItem {
        Home,
        Favorites,
        Reviews,
        Movies,
        Notifications,
        Settings,
        Profile
    }

    _menusView.model: _menus
    _menusView.delegate: SideBarSectionMenu {

        vTypeSelected: root.vTypeSelected

        onSelected: function (vType) {
            root._handleCurrentItemChanged(vType)
        }
    }

    function _handleCurrentItemChanged(vType) {
        root.vTypeSelected = vType
        root.selectedChanged(vType)
    }

    function _handleRefreshMenu() {
        _menusView.model = []
        _menusView.model = _menus
    }

    SideBarControl {
        id: control

        onNotifierLanguageChanged: () => root._handleRefreshMenu()
    }

    readonly property ListModel _menus: ListModel {

        ListElement {
            vTitle: qsTr("Menus")
            vOptions: [
                ListElement {
                    vText: qsTr("Home")
                    vIcon: "qrc:/icons/house"
                    vType: SideBar.TypeMenuItem.Home
                },
                // ListElement {
                //     vText: qsTr("Favorites")
                //     vIcon: "qrc:/icons/favorite"
                //     vType: SideBar.TypeMenuItem.Favorites
                // },
                ListElement {
                    vText: qsTr("Reviews")
                    vIcon: "qrc:/icons/new"
                    vType: SideBar.TypeMenuItem.Reviews
                },
                ListElement {
                    vText: qsTr("Movies")
                    vIcon: "qrc:/icons/movie"
                    vType: SideBar.TypeMenuItem.Movies
                }
            ]
        }

        ListElement {
            vTitle: qsTr("Account")
            vOptions: [
                ListElement {
                    vText: qsTr("Notifications")
                    vIcon: "qrc:/icons/notification"
                    vType: SideBar.TypeMenuItem.Notifications
                },
                ListElement {
                    vText: qsTr("Settings")
                    vIcon: "qrc:/icons/settings"
                    vType: SideBar.TypeMenuItem.Settings
                }
            ]
        }
    }
}
