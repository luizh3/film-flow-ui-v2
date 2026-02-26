cmake_minimum_required(VERSION 3.16)

project(film-flow-ui VERSION 0.1 LANGUAGES CXX)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_AUTOMOC True )
set( CMAKE_AUTOUIC True )
set( CMAKE_AUTORCC True )

set( QT_QML_GENERATE_QMLLS_INI ON )

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick QuickControls2 Qml LinguistTools)

set( APP_NAME main )

qt_standard_project_setup(REQUIRES 6.5)
qt_policy(SET QTP0001 NEW)
qt_policy(SET QTP0004 NEW)

set(QT_QML_GENERATE_QMLLS_INI ON)

qt_add_executable( ${APP_NAME}
    main.cpp
    fonts.qrc
)

qt_add_translations(${APP_NAME}
    TS_FILES
        i18n/film_flow_en_US.ts
        i18n/film_flow_es_ES.ts
        i18n/film_flow_pt_BR.ts
)

qt_add_qml_module( ${APP_NAME}
    URI film-flow-ui
    VERSION 1.0
    QML_FILES
        Main.qml
        ApplicationScreen.qml
        TitleBarForm.ui.qml
        TitleBar.qml
        ResizeManager.qml
        ToastManager.qml
    RESOURCES
        ui/theme/resources.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties( ${APP_NAME} PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appfilm-flow-ui
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    # SKIP_AUTOMOC ON
)

# qt_add_resources(${APP_NAME} translations
#     FILES
#         translations.qrc
# )

# qt_add_resources(${APP_NAME} resources
#     FILES
#         ui/Theme/resources.qrc
# )

add_subdirectory( core )

add_subdirectory( presenter/models )
add_subdirectory( presenter/controls )

add_subdirectory( ui/components )
add_subdirectory( ui/theme )
add_subdirectory( ui/screens )

target_link_libraries( ${APP_NAME}
    PRIVATE
        Qt6::Qml
        Qt6::Quick
        Qt6::Core
        Qt6::QuickControls2
        FF::Core
        FF::Theme
        FF::Controls
        FF::Models
)

include(GNUInstallDirs)

install(TARGETS ${APP_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
