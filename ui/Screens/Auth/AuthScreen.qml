import QtQuick
import QtQuick.Controls

import Ui.Screens
import Ui.Components

AuthScreenForm {
    id: root

    signal success

    stackView.initialItem: loginComponent

    function _onLoading() {
        const screen = root.stackView.push(loginComponent, StackView.Immediate)
        screen.signUp.connect(root._onRegister)
        screen.success.connect(root.success)
    }

    function _onRegister() {
        const screen = root.stackView.push(registerComponent,
                                           StackView.Immediate)
        screen.success.connect(function () {
            root.stackView.pop(StackView.Immediate)
        })
        screen.goBack.connect(function () {
            root.stackView.pop(StackView.Immediate)
        })
    }

    Component {
        id: loginComponent

        LoginScreen {}
    }

    Component {
        id: registerComponent

        RegisterScreen {}
    }

    Component.onCompleted: root._onLoading()
}
