set( LIBRARY_NAME models )
set( LIBRARY_URI Ui.Models )

# Define CORE_INCLUDE_DIR if not already defined
if(NOT DEFINED CORE_INCLUDE_DIR)
    set( CORE_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/core )
endif()

set( SOURCES
    movieslistmodel.cpp
    searchprogramlistmodel.cpp
    reviewslistmodel.cpp
    helper/cardsfetchhelper.cpp
    notificationslistmodel.cpp
    signupmodel.cpp
    reviewmodel.cpp
    genremodel.cpp
    moviemodel.cpp
    mapper/signupmapper.cpp
    mapper/reviewmapper.cpp
    mapper/moviemapper.cpp
    mapper/genremapper.cpp
    mapper/sectionconfigmapper.cpp
    mapper/usermapper.cpp
    sectionconfigmodel.cpp
    usermodel.cpp

)

set( HEADERS
    movieslistmodel.h
    searchprogramlistmodel.h
    models_global.h
    reviewslistmodel.h
    helper/cardsfetchhelper.h
    notificationslistmodel.h
    signupmodel.h
    reviewmodel.h
    genremodel.h
    moviemodel.h
    mapper/signupmapper.h
    mapper/reviewmapper.h
    mapper/moviemapper.h
    mapper/genremapper.h
    mapper/sectionconfigmapper.h
    mapper/usermapper.h
    sectionconfigmodel.h
    usermodel.h
)

qt_add_qml_module(${LIBRARY_NAME}
    URI ${LIBRARY_URI}
    VERSION 1.0
    SOURCES
        ${SOURCES}
        ${HEADERS}
)

target_sources( ${LIBRARY_NAME}
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS FILES ${HEADERS}
)

add_dependencies(
    ${LIBRARY_NAME}
    FF::Core
)

find_package( Qt6 REQUIRED COMPONENTS Core Concurrent )

target_link_libraries( ${LIBRARY_NAME}
    PRIVATE Qt6::Core
    PRIVATE Qt6::Concurrent
    PRIVATE FF::Core
)

target_include_directories( ${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CORE_INCLUDE_DIR}
)

set_target_properties( ${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
target_compile_definitions( ${LIBRARY_NAME} PRIVATE MODELS_LIBRARY )

add_library(FF::Models ALIAS ${LIBRARY_NAME})

