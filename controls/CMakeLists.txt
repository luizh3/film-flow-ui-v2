set( LIBRARY_NAME controls )
set( QT_QML_GENERATE_QMLLS_INI ON )

# Define CORE_INCLUDE_DIR if not already defined
if(NOT DEFINED CORE_INCLUDE_DIR)
    set( CORE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/core )
endif()

set( SOURCES
    moviecontrol.cpp
    authcontrol.cpp
    applicationcontrol.cpp
    homecontrol.cpp
    movieslidercontrol.cpp
    chainbasehandlercalls.cpp
    control.cpp
    chainmanager.cpp
    settingscontrol.cpp
    sidebarcontrol.cpp
    maincontrol.cpp
    reviewprogrammodalcontrol.cpp
    notificationscontrol.cpp
    programreviewcontrol.cpp
)

set( HEADERS
    moviecontrol.h
    authcontrol.h
    applicationcontrol.h
    homecontrol.h
    movieslidercontrol.h
    control.h
    chainhandlercalls.h
    chainbasehandlercalls.h
    chainmanager.h
    settingscontrol.h
    sidebarcontrol.h
    controls_global.h
    maincontrol.h
    reviewprogrammodalcontrol.h
    notificationscontrol.h
    programreviewcontrol.h
)

add_library(
    ${LIBRARY_NAME} SHARED ${SOURCES}
)

qt_add_qml_module( ${LIBRARY_NAME}
  URI ${LIBRARY_NAME}
  VERSION 1.0
  SOURCES
)

find_package( Qt6 REQUIRED COMPONENTS Core Qml Concurrent WebSockets )

target_sources( ${LIBRARY_NAME}
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS FILES ${HEADERS}
)

add_dependencies( ${LIBRARY_NAME} core )

target_link_libraries( ${LIBRARY_NAME}
    PRIVATE Qt6::Core
    PRIVATE Qt6::Qml
    PUBLIC core
    PRIVATE Qt6::Concurrent
    PRIVATE Qt6::WebSockets
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CORE_INCLUDE_DIR}
)

set_target_properties( ${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
target_compile_definitions( ${LIBRARY_NAME} PRIVATE CONTROLS_LIBRARY )
