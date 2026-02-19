set( LIBRARY_NAME controls )
set( MODULE_URI Controls )

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
    profilescreencontrol.cpp
    uicontrolmanager.cpp
    validator/emailvalidator.cpp
    validator/rangevalidator.cpp
    validator/ffvalidator.cpp
    validator/passwordvalidator.cpp
    manager/languagemanager.cpp
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
    profilescreencontrol.h
    uicontrolmanager.h
    validator/emailvalidator.h
    validator/rangevalidator.h
    validator/ffvalidator.h
    validator/passwordvalidator.h
    manager/languagemanager.h
)

add_library(
    ${LIBRARY_NAME} SHARED ${SOURCES}
)

qt_add_qml_module( ${LIBRARY_NAME}
  URI ${MODULE_URI}
  VERSION 1.0
  SOURCES movieslistcontrol.h movieslistcontrol.cpp
  SOURCES notificationslistcontrol.h notificationslistcontrol.cpp
  SOURCES reviewslistcontrol.h reviewslistcontrol.cpp
  SOURCES searchprogramlistcontrol.h searchprogramlistcontrol.cpp
)

find_package( Qt6 REQUIRED COMPONENTS Core Qml Concurrent WebSockets Gui )

target_sources( ${LIBRARY_NAME}
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS FILES ${HEADERS}
)

add_dependencies(
    ${LIBRARY_NAME}
    FF::Theme
    FF::Core
    FF::Models
)

target_link_libraries( ${LIBRARY_NAME}
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Core
    PRIVATE Qt6::Qml
    PRIVATE Qt6::Concurrent
    PRIVATE Qt6::WebSockets
    PRIVATE FF::Core
    PRIVATE FF::Theme
    PRIVATE FF::Models
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/validator
        ${CORE_INCLUDE_DIR}
)

set_target_properties( ${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
target_compile_definitions( ${LIBRARY_NAME} PRIVATE CONTROLS_LIBRARY )

add_library(FF::Controls ALIAS ${LIBRARY_NAME})

