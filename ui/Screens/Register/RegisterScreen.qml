import controls 1.0
import core 1.0
import Ui.Components.Elements

RegisterScreenForm {
    id: root

    signal goBack
    signal success

    backButton.onClicked: root.goBack()
    signUpButton.onClicked: root._handleSignUp()

    FFInputStateValidator {
        id: inputStateValidator

        inputs: [root.emailField, root.passwordRepeatField, root.passwordField, root.nameField]
        onIsValidChanged: root._handleFieldsValid()
    }

    function _handleFieldsValid() {
        root.signUpButton.vState
                = inputStateValidator.isValid ? FFButton.State.Active : FFButton.State.Disabled
    }

    property SignUp signUp: SignUp {
        name: root.nameField.vText
        email: root.emailField.vText
        password: root.passwordField.vText
    }

    function _handleSignUp() {
        root.setEnabledFields(false)
        root.signUpButton.vState = FFButton.State.Loading
        control.signUp(signUp)
    }

    function _handleSuccess() {
        root.success()
    }

    function setEnabledFields(isEnabled) {
        root.enabled = isEnabled
    }

    function _handleError() {
        root.setEnabledFields(true)
        root.signUpButton.vState = FFButton.State.Active
        root.signUpButton.vType = FFButton.Type.Error
    }

    AuthControl {
        id: control

        onSuccess: root._handleSuccess()
        onError: root._handleError()
    }
}
