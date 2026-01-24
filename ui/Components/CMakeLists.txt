set( MODULE_NAME Components )

set( QML_FILES
    SideBar/SideBar.qml
    SideBar/SideBarForm.ui.qml
    SideBar/SideBarItem.qml
    SideBar/SideBarItemForm.ui.qml
    SideBar/SideBarSectionMenu.qml
    SideBar/SideBarSectionMenuForm.ui.qml
    ImageGradient/ImageGradient.qml
    Header/Header.qml
    Header/HeaderForm.ui.qml
    MovieSlider/MovieSliderForm.ui.qml
    MovieSlider/MovieSlider.qml
    CardMovie/CardMovieForm.ui.qml
    CardMovie/CardMovie.qml
    CardMovieList/CardMovieList.qml
    CardMovieList/CardMovieListForm.ui.qml
    SearchResultCard.qml
    SearchResultCardForm.ui.qml
    SearchProgramResultPopup.qml
    SearchProgramResultPopupForm.ui.qml
    ReviewProgramModal.qml
    ReviewProgramModalForm.ui.qml
    ProgramReview.qml
    ProgramReviewForm.ui.qml
    PopupManager.qml
    GenericModal.qml
    ToastManager.qml
    ScreenManager.qml
    GenericScreen.qml
    NotificationsPopup.qml
    NotificationsPopupForm.ui.qml
    GenericPopup.qml
    NotificationCard.qml
    NotificationCardForm.ui.qml
    ThemePickerForm.ui.qml
    ThemePicker.qml
)

qt_add_qml_module( ${MODULE_NAME}
    URI Ui.Components
    VERSION 1.0
    RESOURCES qmldir
    QML_FILES
        ${QML_FILES}
)

add_subdirectory( Elements )

