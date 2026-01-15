import QtQuick
import QtQuick.Controls

import Ui.Theme

Item {
    id: root

    function pop() {
        if (stack.depth === 1) {
            clear()
            return
        }

        stack.pop()
    }

    function push(popup, props) {
        const popupCreated = stack.push(popup, props)

        popupCreated.close.connect(function onRemove() {
            popupCreated.close.disconnect(onRemove)
            root.pop()
        })

        return popupCreated
    }

    function clear() {
        stack.clear()
    }

    StackView {
        id: stack
        anchors.fill: parent

        property int _duration: Durations.normal

        visible: stack.depth > 0
        opacity: stack.visible ? 1 : 0

        Behavior on opacity {
            NumberAnimation {
                duration: stack._duration
            }
        }

        background: Rectangle {
            color: "#000000"
            opacity: stack.depth > 0 ? 0.5 : 0

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
