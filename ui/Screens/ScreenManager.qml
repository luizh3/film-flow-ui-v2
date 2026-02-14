import QtQuick
import QtQuick.Controls

// TODO maybe create a Ui.Screens.Commons to move screenManager
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
        opacity: stack.visible ? 1 : 0

        anchors.fill: parent

        property int _duration: 0

        Behavior on opacity {
            NumberAnimation {
                duration: stack._duration
            }
        }

        background: Rectangle {
            color: "#000000"

            Behavior on opacity {
                NumberAnimation {
                    duration: stack._duration
                }
            }

            MouseArea {
                anchors.fill: parent
                enabled: stack.depth > 0
                hoverEnabled: false
            }
        }

        pushEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: stack._duration
            }
        }

        pushExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: stack._duration
            }
        }

        popEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to: 1
                duration: stack._duration
            }
        }

        popExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to: 0
                duration: stack._duration
            }
        }
    }
}
