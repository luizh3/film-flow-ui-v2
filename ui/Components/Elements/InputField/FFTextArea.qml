import QtQuick

import Ui.Theme

FFTextAreaForm {
    id: root

    enum Type {
        Primary,
        Secundary
    }

    label.text: root.vLabel
    label.visible: root.vLabel !== ""

    signal confirmed

    function clear() {
        root.vText = ""
    }

    function _toPrimaryType() {
        background.color = Colors.grey500
    }

    function _toSecundaryType() {
        background.color = "transparent"
    }

    function _changeType() {
        switch (root.vType) {
        case FFTextField.Type.Primary:
            root._toPrimaryType()
            break
        case FFTextField.Type.Secundary:
            root._toSecundaryType()
            break
        }
    }

    states: [
        State {
            name: "Active"
            when: root.enabled && !root.textArea.focus

            PropertyChanges {

                root {
                    background {
                        border.color: Colors.grey400
                    }

                    label {
                        opacity: 1
                    }
                }
            }
        },
        State {
            name: "Disabled"
            when: !root.enabled

            PropertyChanges {

                root {

                    background {
                        border.color: Colors.grey400
                        opacity: 0.5
                    }

                    label {
                        opacity: 0.5
                    }
                }
            }
        },
        State {
            name: "Focus"
            when: root.enabled && root.textArea.focus

            PropertyChanges {

                root {
                    background {
                        border.color: Colors.primary500
                    }

                    label {
                        opacity: 1
                    }
                }
            }
        }
    ]

    Component.onCompleted: root._changeType()
}
