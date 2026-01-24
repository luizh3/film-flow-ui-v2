cmake_minimum_required(VERSION 3.16)

project(film-flow-ui VERSION 0.1 LANGUAGES CXX)

set( CMAKE_CXX_STANDARD 17 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_AUTOMOC True )
set( CMAKE_AUTOUIC True )
set( CMAKE_AUTORCC True )

set(ENV{QMLLS_BUILD_DIRS} ${CMAKE_BINARY_DIR})

set( QT_QML_GENERATE_QMLLS_INI ON )

set( CORE_LIBRARY_NAME core )
set( CORE_INCLUDE_DIR ${CMAKE_SOURCE_DIR} )

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick QuickControls2 Qml LinguistTools)

set( APP_NAME main )

LIST( APPEND QML_SOURCE_PATHS "${CMAKE_SOURCE_DIR}")

# set( QML_IMPORT_PATH ${QML_SOURCE_PATHS} CACHE STRING "" FORCE)

set(QML_IMPORT_PATH
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/ui
    ${CMAKE_SOURCE_DIR}/ui/Components
    ${CMAKE_SOURCE_DIR}/ui/Screens
    ${CMAKE_SOURCE_DIR}/ui/Theme
    CACHE STRING "" FORCE
)

qt_standard_project_setup(REQUIRES 6.5)
qt_policy(SET QTP0001 NEW)
#qt_policy(SET QTP0004 NEW)

set(QT_QML_GENERATE_QMLLS_INI ON)

qt_add_executable( ${APP_NAME}
    main.cpp
    ${CORE_INCLUDE_DIR}
    translations.qrc
    fonts.qrc
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
    RESOURCES
        ui/theme/resources.qrc
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties( ${APP_NAME} PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appfilm-flow-ui
    # QMLLS_BUILD_DIRS ${CMAKE_BINARY_DIR}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    SKIP_AUTOMOC ON
)

# qt_add_resources(${APP_NAME} translations
#     FILES
#         translations.qrc
# )

# qt_add_resources(${APP_NAME} resources
#     FILES
#         ui/Theme/resources.qrc
# )

target_include_directories( ${APP_NAME}
    PUBLIC
        ${CORE_INCLUDE_DIR}
)

target_link_libraries( ${APP_NAME}
    PRIVATE Qt6::Qml
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Core
    PRIVATE Qt6::QuickControls2
    PRIVATE FF::Core
    PRIVATE FF::Theme
    PRIVATE FF::Controls
    PRIVATE FF::Models
)

add_subdirectory( core )
add_subdirectory( controls )

add_subdirectory( ui/models )
add_subdirectory( ui/Components )
add_subdirectory( ui/Theme )
add_subdirectory( ui/Screens )

include(GNUInstallDirs)
install(TARGETS ${APP_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
