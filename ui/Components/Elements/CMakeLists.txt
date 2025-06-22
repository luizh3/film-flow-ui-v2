set( MODULE_NAME Elements )

set( MODULE_URI Ui.Components.Elements )

set( QML_FILES
    FFIcon.qml
    InputField/FFTextField.qml
    InputField/FFTextFieldForm.ui.qml
    InputField/FFPasswordTextField.qml
    InputField/FFInputStateValidator.qml
    Button/FFButton.qml
    Button/FFButtonForm.ui.qml
    Button/FFButtonIcon.qml
    Button/FFButtonIconForm.ui.qml
    Button/FFButtonNavigation.qml
    Button/FFButtonNavigationForm.ui.qml
    LoadingCircle/FFLoadingCircleForm.ui.qml
    LoadingCircle/FFLoadingCircle.qml
    FFSkeletonLoading.qml
    FFProfileIcon.qml
    FFScoreBadget.qml
    FFImageRounded.qml
    FFLogo.qml
)

set( RESOURCES
    qmldir
)

qt_add_qml_module( ${MODULE_NAME}
    URI ${MODULE_URI}
    VERSION 1.0
    QML_FILES
        ${QML_FILES}
    RESOURCES
        ${RESOURCES}
)
