import QtQuick

import "../Button"

FFTextField {
    id: root
    vLabel: qsTr("Password")
    vPlaceHolderText: ""
    vIconRight: "qrc:/icons/eye-off"
    buttonIconRight.vType: FFButtonIcon.Type.FlatSecundary
    buttonIconRight.onClicked: root._handlePasswordVisible();
    textField.echoMode: TextInput.Password

    function _handlePasswordVisible() {

        if( root.textField.echoMode == TextInput.Password ){
            root.textField.echoMode = TextInput.Normal;
            root.vIconRight = "qrc:/icons/eye";
            return;
        }

        root.textField.echoMode = TextInput.Password;
        root.vIconRight = "qrc:/icons/eye-off"
    }
}
