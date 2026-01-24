set( MODULE_NAME theme )
set( QT_QML_GENERATE_QMLLS_INI ON )

set( MODULE_URI Ui.Theme )

set( RESOURCES
    qmldir
)

set( QML_SINGLETONS
    Colors.qml
    Spacings.qml
    Radius.qml
    Fonts.qml
    Icons.qml
    Durations.qml
)

set_source_files_properties(
    ${QML_SINGLETONS}
    PROPERTIES QT_QML_SINGLETON_TYPE TRUE
)

qt_add_qml_module( ${MODULE_NAME}
    URI ${MODULE_URI}
    VERSION 1.0
    QML_FILES
        ${QML_SINGLETONS}
    RESOURCES
        ${RESOURCES}
        resources.qrc
    SOURCES
        manager/themecolormanager.cpp
        factory/themecolorfactory.cpp
        models/coloritemmodel.cpp

        manager/themecolormanager.h
        factory/themecolorfactory.h
        models/colorrole.h
        models/themecolormodel.h
        models/coloritemmodel.h
        theme_global.h

)

find_package( Qt6 REQUIRED COMPONENTS Core Qml )

target_link_libraries(${MODULE_NAME}
    PUBLIC
        Qt6::Core
        Qt6::Qml
)

target_include_directories(${MODULE_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_definitions( ${MODULE_NAME}
    PRIVATE THEME_LIBRARY
)

add_library(FF::Theme ALIAS ${MODULE_NAME})

