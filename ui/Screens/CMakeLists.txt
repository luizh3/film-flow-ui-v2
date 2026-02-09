set( MODULE_NAME screens )
set( MODULE_URI Ui.Screens )

set( QML_FILES
    home/HomeScreen.qml
    home/HomeScreenForm.ui.qml
    auth/AuthScreenForm.ui.qml
    auth/AuthScreen.qml
    movie/MovieScreen.qml
    movie/MovieScreenForm.ui.qml
    profile/ProfileScreen.qml
    profile/ProfileScreenForm.ui.qml
    review/ReviewScreenForm.ui.qml
    review/ReviewScreen.qml
    program/ProgramsScreen.qml
    program/ProgramsScreenForm.ui.qml
    settings/SettingsScreen.qml
    settings/SettingsScreenForm.ui.qml
    login/LoginScreen.qml
    login/LoginScreenForm.ui.qml
    register/RegisterScreenForm.ui.qml
    register/RegisterScreen.qml
    ScreenManager.qml
    PopupManager.qml
)

qt_add_qml_module( ${MODULE_NAME}
    URI ${MODULE_URI}
    VERSION 1.0
    QML_FILES
        ${QML_FILES}
)

target_link_libraries( ${MODULE_NAME}
    PRIVATE FF::Models
)
