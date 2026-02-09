set( MODULE_NAME elements )
set( MODULE_URI Ui.Components.Elements )

set( QML_FILES
    FFIcon.qml
    inputfield/FFTextField.qml
    inputfield/FFTextFieldForm.ui.qml
    inputfield/FFPasswordTextField.qml
    inputfield/FFInputStateValidator.qml
    inputfield/FFTextArea.qml
    inputfield/FFTextAreaForm.ui.qml
    button/FFButton.qml
    button/FFButtonForm.ui.qml
    button/FFButtonIcon.qml
    button/FFButtonIconForm.ui.qml
    button/FFButtonNavigation.qml
    button/FFButtonNavigationForm.ui.qml
    button/FFButtonReactionForm.ui.qml
    button/FFButtonReaction.qml
    button/FFButtonScroll.qml
    button/FFButtonScrollForm.ui.qml
    loadingcircle/FFLoadingCircleForm.ui.qml
    loadingcircle/FFLoadingCircle.qml
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

qt_add_qml_module( ${MODULE_NAME}
    URI ${MODULE_URI}
    VERSION 1.0
    QML_FILES
        ${QML_FILES}
)
