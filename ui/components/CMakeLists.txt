set( MODULE_NAME components )
set( LIBRARY_URI Ui.Components )

set( QML_FILES
    sidebar/SideBar.qml
    sidebar/SideBarForm.ui.qml
    sidebar/SideBarItem.qml
    sidebar/SideBarItemForm.ui.qml
    sidebar/SideBarSectionMenu.qml
    sidebar/SideBarSectionMenuForm.ui.qml
    imagegradient/ImageGradient.qml
    header/Header.qml
    header/HeaderForm.ui.qml
    movieslider/MovieSliderForm.ui.qml
    movieslider/MovieSlider.qml
    cardmovie/CardMovieForm.ui.qml
    cardmovie/CardMovie.qml
    cardmovielist/CardMovieList.qml
    cardmovielist/CardMovieListForm.ui.qml
    SearchResultCard.qml
    SearchResultCardForm.ui.qml
    SearchProgramResultPopup.qml
    SearchProgramResultPopupForm.ui.qml
    ReviewProgramModal.qml
    ReviewProgramModalForm.ui.qml
    ProgramReview.qml
    ProgramReviewForm.ui.qml
    GenericModal.qml
    GenericScreen.qml
    NotificationsPopup.qml
    NotificationsPopupForm.ui.qml
    GenericPopup.qml
    NotificationCard.qml
    NotificationCardForm.ui.qml
    ThemePickerForm.ui.qml
    ThemePicker.qml
    FooterScroll.qml
    FooterScrollForm.ui.qml
    BadgetProviderForm.ui.qml
    BadgetProvider.qml
)

add_library(${MODULE_NAME})

qt_add_qml_module( ${MODULE_NAME}
    URI ${LIBRARY_URI}
    VERSION 1.0
    QML_FILES
        ${QML_FILES}
    IMPORTS
        Presenter.Controls

)

target_link_libraries( ${MODULE_NAME}
    PUBLIC FF::Controls
)

add_subdirectory( elements )
