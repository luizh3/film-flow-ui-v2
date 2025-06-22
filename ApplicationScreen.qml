import QtQuick
import QtQuick.Layouts

import Ui.Theme
import Ui.Screens
import Ui.Components

import controls 1.0

Item {
    id: root
    implicitWidth: 1280
    implicitHeight: 768

    function _handleChangeItem(vType) {

        console.log(vType)

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

        Loader {
            id: loaderMainScreen
            Layout.fillWidth: true
            Layout.fillHeight: true
            sourceComponent: movieScreenComponente
        }
    }

    Component {
        id: homeComponent

        Home {}
    }

    Component {
        id: favoritesComponent

        Item {}
    }

    Component {
        id: movieScreenComponente

        MovieScreen {}
    }

    Component {
        id: reviewsComponent

        Item {}
    }

    ApplicationControl {
        id: control
    }

    // Component.onCompleted: control.configs();
}
