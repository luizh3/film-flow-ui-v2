set( LIBRARY_NAME controls )
set( MODULE_URI Presenter.Controls )

set( QT_QML_GENERATE_QMLLS_INI ON )

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
    mapper/signupmapper.cpp
    mapper/reviewmapper.cpp
    mapper/moviemapper.cpp
    mapper/genremapper.cpp
    mapper/sectionconfigmapper.cpp
    mapper/usermapper.cpp
    mapper/typeprogramenummapper.cpp
    movieslistcontrol.cpp
    notificationslistcontrol.cpp
    reviewslistcontrol.cpp
    searchprogramlistcontrol.cpp
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
    mapper/signupmapper.h
    mapper/reviewmapper.h
    mapper/moviemapper.h
    mapper/genremapper.h
    mapper/sectionconfigmapper.h
    mapper/usermapper.h
    mapper/typeprogramenummapper.h
    movieslistcontrol.h
    notificationslistcontrol.h
    reviewslistcontrol.h
    searchprogramlistcontrol.h
)

add_library(${LIBRARY_NAME} SHARED)

qt_add_qml_module( ${LIBRARY_NAME}
  URI ${MODULE_URI}
  VERSION 1.0
  IMPORTS
      Presenter.Models
)

find_package( Qt6 REQUIRED COMPONENTS Qml Gui Core )

target_sources( ${LIBRARY_NAME}
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS FILES ${HEADERS}
)

target_link_libraries( ${LIBRARY_NAME}
    PUBLIC
        FF::Core
        FF::Theme
        FF::Models
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/validator
)

set_target_properties( ${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
target_compile_definitions( ${LIBRARY_NAME} PRIVATE CONTROLS_LIBRARY )

add_library(FF::Controls ALIAS ${LIBRARY_NAME})

