import QtQuick

import Ui.Theme

FFButtonForm {
    id: root

    enum Type {
        Primary,
        Secundary,
        Error
    }

    enum State {
        Active,
        Loading,
        Disabled
    }

    onVTypeChanged: root._setType()

    property int vType: FFButton.Type.Primary
    property int vState: FFButton.State.Active

    property string vIcon: Icons.outlined.check
    property string vIconError: Icons.outlined.replay

    function _changeIcon(icon) {
        root.icon.source = icon
    }

    function _changeType(color, icon) {
        root.background.color = color
        root._changeIcon(icon)
    }

    function _toPrimaryType() {
        root._changeType(Colors.primary, root.vIcon)
    }

    function _toSecundaryType() {
        root._changeType(Colors.secundary, root.vIcon)
    }

    function _toErrorType() {
        root._changeType(Colors.error, root.vIconError)
    }

    function _setType() {

        switch (root.vType) {
        case FFButton.Type.Primary:
            root._toPrimaryType()
            break
        case FFButton.Type.Secundary:
            root._toSecundaryType()
            break
        case FFButton.Type.Error:
            root._toErrorType()
            break
        }
    }

    states: [
        State {
            name: "Active"
            when: root.vState === FFButton.State.Active
            PropertyChanges {

                root {

                    contentItem {
                        visible: true
                    }

                    loading {
                        visible: false
                    }

                    enabled: true
                    opacity: 1
                }
            }
        },
        State {
            name: "Loading"
            when: root.vState === FFButton.State.Loading
            PropertyChanges {
                root {

                    contentItem {
                        visible: false
                    }

                    loading {
                        visible: true
                    }

                    enabled: false
                    opacity: 1
                }
            }
        },
        State {
            name: "Disabled"
            when: root.vState === FFButton.State.Disabled
            PropertyChanges {
                root {

                    contentItem {
                        visible: true
                    }

                    loading {
                        visible: false
                    }

                    enabled: false
                    opacity: 0.5
                }
            }
        }
    ]

    function _onInit() {
        root._changeIcon(root.vIcon)
        root._setType()
    }

    function _setStateByEnabled() {

        if (root.enabled) {
            root.vState = FFButton.State.Active
            return
        }

        root.vState = FFButton.State.Disabled
    }

    Component.onCompleted: root._onInit()
    onEnabledChanged: root._setStateByEnabled()
}
