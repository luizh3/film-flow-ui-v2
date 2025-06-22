set( MODULE_NAME Screens )

set( QML_FILES
    Home/Home.qml
    Home/HomeForm.ui.qml
    Auth/AuthForm.ui.qml
    Auth/Auth.qml
    Movie/MovieScreen.qml
    Movie/MovieScreenForm.ui.qml
)

qt_add_qml_module( ${MODULE_NAME}
    URI Ui.Screens
    VERSION 1.0
    RESOURCES qmldir
    QML_FILES
        ${QML_FILES}
)
