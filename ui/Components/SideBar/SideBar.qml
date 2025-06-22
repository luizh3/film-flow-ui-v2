pragma ComponentBehavior: Bound

import QtQuick

SideBarForm {
    id: root

    objectName: "SideBar"

    signal selectedChanged( int vType )

    enum TypeMenuItem {
        Home,
        Favorites,
        Reviews,
        Movies,
        Notifications,
        Settings
    }

    _menusView.model: _menus
    _menusView.delegate: SideBarSectionMenu {

        vTypeSelected: root.vTypeSelected

        onSelected: function( vType ){
            root._handleCurrentItemChanged( vType )
        }
    }

    function _handleCurrentItemChanged( vType ) {
        root.vTypeSelected = vType;
        root.selectedChanged( vType )
    }

    readonly property ListModel _menus: ListModel {

        ListElement {
            vTitle: qsTr("Menus")
            vOptions: [
                ListElement {
                    vText: "Home"
                    vIcon: "qrc:/icons/house"
                    vType: SideBar.TypeMenuItem.Home
                },
                ListElement {
                    vText: "Favorites"
                    vIcon: "qrc:/icons/favorite"
                    vType: SideBar.TypeMenuItem.Favorites
                },
                ListElement {
                    vText: "Reviews"
                    vIcon: "qrc:/icons/new"
                    vType: SideBar.TypeMenuItem.Reviews
                },
                ListElement {
                    vText: "Movies"
                    vIcon: "qrc:/icons/movie"
                    vType: SideBar.TypeMenuItem.Movies
                }
            ]
        }

        ListElement {
            vTitle: qsTr("Account")
            vOptions: [
                ListElement {
                    vText: "Notifications"
                    vIcon: "qrc:/icons/notification"
                    vType: SideBar.TypeMenuItem.Notifications
                },
                ListElement {
                    vText: "Settings"
                    vIcon: "qrc:/icons/settings"
                    vType: SideBar.TypeMenuItem.Settings
                }
            ]
        }

    }


}
