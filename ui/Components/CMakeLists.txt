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
    Login/LoginForm.ui.qml
    Login/Login.qml
    Register/RegisterForm.ui.qml
    Register/Register.qml
    CardMovieList/CardMovieList.qml
    CardMovieList/CardMovieListForm.ui.qml
)

qt_add_qml_module( ${MODULE_NAME}
    URI Ui.Components
    VERSION 1.0
    RESOURCES qmldir
    QML_FILES
        ${QML_FILES}
)

add_subdirectory( Elements )

