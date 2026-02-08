set( MODULE_NAME screens )
set( MODULE_URI Ui.Screens )

set( QML_FILES
    Home/HomeScreen.qml
    Home/HomeScreenForm.ui.qml
    Auth/AuthScreenForm.ui.qml
    Auth/AuthScreen.qml
    Movie/MovieScreen.qml
    Movie/MovieScreenForm.ui.qml
    Profile/ProfileScreen.qml
    Profile/ProfileScreenForm.ui.qml
    Review/ReviewScreenForm.ui.qml
    Review/ReviewScreen.qml
    Program/ProgramsScreen.qml
    Program/ProgramsScreenForm.ui.qml
    Settings/SettingsScreen.qml
    Settings/SettingsScreenForm.ui.qml
    Login/LoginScreen.qml
    Login/LoginScreenForm.ui.qml
    Register/RegisterScreenForm.ui.qml
    Register/RegisterScreen.qml
    ScreenManager.qml
    PopupManager.qml
)

qt_add_qml_module( ${MODULE_NAME}
    URI ${MODULE_URI}
    VERSION 1.0
    RESOURCES qmldir
    QML_FILES
        ${QML_FILES}
)
