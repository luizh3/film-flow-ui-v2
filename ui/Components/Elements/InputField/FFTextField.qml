import QtQuick

import Ui.Theme

FFTextFieldForm {
    id: root

    enum Type {
        Primary,
        Secundary
    }

    textField.onTextChanged: root._onTextChanged()

    label.text: root.vLabel
    label.visible: root.vLabel !== "";

    buttonIconLeft.visible: root.vIconLeft !== "";
    buttonIconRight.visible: root.vIconRight !== "";
    labelError.visible: root.labelError.text !== "" && !root.vIsValid;

    buttonIconLeft.vIcon: root.vIconLeft
    buttonIconRight.vIcon: root.vIconRight

    onVValidatorChanged: root._setValidator()

    function _onTextChanged() {
        root._setIsInicialized();
        root._setTextError();
    }

    function _setTextError() {

        if( !root.vValidator ){
            return;
        }

        root._textError = root.vValidator.vError
    }

    function _setValidator() {

        if( !root.vValidator ){
            return;
        }

        root.textField.validator = root.vValidator
    }

    function _setIsInicialized() {
        root._isInicialized = true;
    }

    function _toPrimaryType() {
        background.color = Colors.grey500
    }

    function _toSecundaryType() {
        background.color = "transparent"
    }

    function _changeType() {
        switch( root.vType ) {
        case FFTextField.Type.Primary:
            root._toPrimaryType()
            break;
        case FFTextField.Type.Secundary:
            root._toSecundaryType();
            break;
        }
    }

    states: [
        State {
            name: "Active"
            when: root.enabled && !root.textField.focus && root.vIsValid

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
            when: root.enabled && root.textField.focus && root.vIsValid

            PropertyChanges {

                root {
                    background {
                        border.color: Colors.primary
                    }

                    label {
                        opacity: 1
                    }

                }

            }
        },
        State {
            name: "Invalid"
            when: root.enabled && !root.vIsValid

            PropertyChanges {

                root {
                    background {
                        border.color: Colors.error
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
