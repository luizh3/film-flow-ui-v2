set( LIBRARY_NAME core )

set( SOURCES
    controller/moviecontroller.cpp
    controller/applicationcontroller.cpp
    network/httpclient.cpp
    singleton/integrationmanager.cpp
    entities/integration.cpp
    network/endpoint/authendpoint.cpp
    entities/user.cpp
    entities/session.cpp
    controller/authcontroller.cpp
    network/response/response.cpp
    entities/signup.cpp
    entities/signin.cpp
    validator/emailvalidator.cpp
    validator/rangevalidator.cpp
    validator/ffvalidator.cpp
    validator/passwordvalidator.cpp
    network/endpoint/filmflowconfigendpoint.cpp
    network/endpoint/filmflowendpoint.cpp
    manager/applicationmanager.cpp
    entities/configs.cpp
    entities/sectionsconfig.cpp
    entities/programconfig.cpp
    network/endpoint/filmflowsectionendpoint.cpp
    network/request/sectionrequest.cpp
    controller/sectioncontroller.cpp
    entities/movieinformation.cpp
    entities/searchmovies.cpp
    entities/genre.cpp
    entities/pagination.cpp
    helper/taskrunhelper.cpp
)

set( HEADERS
    controller/moviecontroller.h
    controller/applicationcontroller.h
    network/httpclient.h
    singleton/integrationmanager.h
    entities/integration.h
    network/endpoint/authendpoint.h
    entities/user.h
    entities/session.h
    controller/authcontroller.h
    network/response/response.h
    network/httpstatuscode.h
    entities/signup.h
    entities/signin.h
    validator/emailvalidator.h
    validator/rangevalidator.h
    validator/ffvalidator.h
    validator/passwordvalidator.h
    helper/regex/regexhelper.h
    network/endpoint/filmflowconfigendpoint.h
    network/endpoint/filmflowendpoint.h
    manager/applicationmanager.h
    entities/configs.h
    entities/sectionsconfig.h
    entities/programconfig.h
    entities/genre.h
    entities/typeprogramenum.h
    network/endpoint/filmflowsectionendpoint.h
    network/request/sectionrequest.h
    controller/sectioncontroller.h
    entities/pagination.h
    entities/movieinformation.h
    entities/searchmovies.h
    helper/taskrunhelper.h
    core_global.h
)

add_library(
    ${LIBRARY_NAME} SHARED
)

qt_add_qml_module( ${LIBRARY_NAME}
  URI ${LIBRARY_NAME}
  VERSION 1.0
)

target_sources( ${LIBRARY_NAME}
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS FILES ${HEADERS}
)

find_package( Qt6 REQUIRED COMPONENTS Core Network Qml Gui Concurrent )

target_link_libraries( ${LIBRARY_NAME} PUBLIC
    PRIVATE Qt6::Core
    PRIVATE Qt6::Network
    PRIVATE Qt6::Qml
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Concurrent
)

target_include_directories(${LIBRARY_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/entities
  ${CMAKE_CURRENT_SOURCE_DIR}/controller
  ${CMAKE_CURRENT_SOURCE_DIR}/network
  ${CMAKE_CURRENT_SOURCE_DIR}/manager
  ${CMAKE_CURRENT_SOURCE_DIR}/singleton
  ${CMAKE_CURRENT_SOURCE_DIR}/validator
  ${CMAKE_CURRENT_SOURCE_DIR}/helper
)

set_target_properties( ${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )
target_compile_definitions( ${LIBRARY_NAME} PRIVATE CORE_LIBRARY )
