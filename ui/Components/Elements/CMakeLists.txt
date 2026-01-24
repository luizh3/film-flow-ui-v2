set( MODULE_NAME Elements )

set( MODULE_URI Ui.Components.Elements )

set( QML_FILES
    FFIcon.qml
    InputField/FFTextField.qml
    InputField/FFTextFieldForm.ui.qml
    InputField/FFPasswordTextField.qml
    InputField/FFInputStateValidator.qml
    InputField/FFTextArea.qml
    InputField/FFTextAreaForm.ui.qml
    Button/FFButton.qml
    Button/FFButtonForm.ui.qml
    Button/FFButtonIcon.qml
    Button/FFButtonIconForm.ui.qml
    Button/FFButtonNavigation.qml
    Button/FFButtonNavigationForm.ui.qml
    Button/FFButtonReactionForm.ui.qml
    Button/FFButtonReaction.qml
    Button/FFButtonScroll.qml
    Button/FFButtonScrollForm.ui.qml
    LoadingCircle/FFLoadingCircleForm.ui.qml
    LoadingCircle/FFLoadingCircle.qml
    FFSkeletonLoading.qml
    FFProfileIcon.qml
    FFScoreBadget.qml
    FFImageRounded.qml
    FFLogo.qml
    FFBadget.qml
    FFSectionHeader.qml
    FFRatingStars.qml
    FFRatingStarsForm.ui.qml
    FFToast.qml
    FFToastForm.ui.qml
    FFToolTip.qml
    FFActionPill.qml
    FFActionPillForm.ui.qml
    FFComboBox.qml
    FFComboBoxForm.ui.qml
    FFColorItem.qml
    FFColorItemForm.ui.qml
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
