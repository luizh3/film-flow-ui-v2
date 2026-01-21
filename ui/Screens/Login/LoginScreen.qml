import Ui.Components.Elements
import controls 1.0

LoginScreenForm {
    id: root

    signal signUp
    signal success

    mouseAreaSignUp.onClicked: root.signUp()

    FFInputStateValidator {
        id: inputStateValidator

        inputs: [root.emailField, root.passwordField]
        onIsValidChanged: root._handleFieldsValid()
    }

    function _handleFieldsValid() {
        root.loginButton.vState
                = inputStateValidator.isValid ? FFButton.State.Active : FFButton.State.Disabled
    }

    function _handleLogin() {
        root.setEnabledFields(false)
        root.loginButton.vState = FFButton.State.Loading
        control.signIn(passwordField.vText, emailField.vText)
    }

    function _handleError() {
        root.setEnabledFields(true)
        root.loginButton.vState = FFButton.State.Active
        root.loginButton.vType = FFButton.Type.Error
    }

    function setEnabledFields(isEnabled) {
        root.enabled = isEnabled
    }

    function _handleSuccess() {
        root.success()
    }

    AuthControl {
        id: control

        onError: root._handleError()
        onSuccess: root._handleSuccess()
    }

    loginButton.onClicked: root._handleLogin()
}
