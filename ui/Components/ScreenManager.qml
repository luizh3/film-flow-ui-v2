import QtQuick
import QtQuick.Controls

import Ui.Screens

// TODO tirar esse cara dos components, nem faz sentido estar aqui kkkkkkk
Item {
    id: root

    enum Route {
        MOVIE,
        PROFILE
    }

    function navigate(tpRoute, props = {}) {
        switch (tpRoute) {
        case ScreenManager.Route.MOVIE:
            return root.push(movieScreenComponente, props)
        case ScreenManager.Route.PROFILE:
            return root.push(profileComponent, props)
        }
    }

    Component {
        id: movieScreenComponente

        MovieScreen {}
    }

    Component {
        id: profileComponent

        ProfileScreen {}
    }

    function pop() {
        if (stack.depth === 1) {
            clear()
            return
        }

        stack.pop()
    }

    function push(screen, props = {}) {
        const screenCreated = stack.push(screen, props)

        screenCreated.close.connect(function onRemove() {
            screenCreated.close.disconnect(onRemove)
            root.pop()
        })

        return screenCreated
    }

    function clear() {

        if (stack.empty) {
            return
        }

        stack.clear()
    }

    StackView {
        id: stack
        visible: stack.depth > 0
        anchors.fill: parent

        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: 0
            }
        }

        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: 0
            }
        }

        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: 0
            }
        }

        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: 0
            }
        }
    }
}
