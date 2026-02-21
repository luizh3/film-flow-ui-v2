set( LIBRARY_NAME models )
set( LIBRARY_URI Presenter.Models )

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
    sectionconfigmodel.h
    enum/presentertypeprogramenum.h
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

find_package( Qt6 REQUIRED COMPONENTS Core Concurrent )

target_link_libraries( ${LIBRARY_NAME}
    PRIVATE Qt6::Core
    PRIVATE Qt6::Concurrent
)

target_include_directories( ${LIBRARY_NAME}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/enum
)

set_target_properties( ${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
target_compile_definitions( ${LIBRARY_NAME} PRIVATE MODELS_LIBRARY )

add_library(FF::Models ALIAS ${LIBRARY_NAME})

