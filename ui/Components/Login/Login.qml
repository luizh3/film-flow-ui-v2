import Ui.Components.Elements
import controls 1.0

LoginForm {
    id: root

    signal signUp;
    signal success;

    mouseAreaSignUp.onClicked: root.signUp();

    FFInputStateValidator {
        id: inputStateValidator

        inputs: [
            root.emailField,
            root.passwordField
        ]
    }

    function _handleLogin() {
        root.setEnabledFields( false );
        root.loginButton.vState = FFButton.State.Loading;
        control.signIn( passwordField.vText, emailField.vText )
    }

    function _handleError() {
        root.setEnabledFields( true );
        root.loginButton.vState = FFButton.State.Active;
        root.loginButton.vType = FFButton.Type.Error;
    }

    function setEnabledFields( isEnabled ) {
        root.enabled = isEnabled;
    }

    function _handleSuccess() {
        root.success()
    }

    AuthControl {
        id: control

        onError: root._handleError()
        onSuccess: root._handleSuccess()
    }

    loginButton.onClicked: root._handleLogin();
}
