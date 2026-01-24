set( LIBRARY_NAME core )

set(CMAKE_AUTOMOC ON)

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
    network/endpoint/filmflowmultiendpoint.cpp
    network/request/multirequest.cpp
    controller/multicontroller.cpp
    network/request/multidetailsrequest.cpp
    manager/languagemanager.cpp
    network/endpoint/filmflowreviewendpoint.cpp
    controller/reviewcontroller.cpp
    entities/review.cpp
    entities/reviewsresult.cpp
    network/request/paginationrequest.cpp
    websocket/notificationws.cpp
    entities/notification.cpp
    entities/notificationreviewlike.cpp
    manager/notificationmanager.cpp
    controller/notificationcontroller.cpp
    network/endpoint/filmflownotificationendpoint.cpp
    entities/notificationsresult.cpp
    controller/reviewlikecontroller.cpp
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
    network/endpoint/filmflowmultiendpoint.h
    network/request/multirequest.h
    controller/multicontroller.h
    network/request/multidetailsrequest.h
    manager/languagemanager.h
    entities/review.h
    network/endpoint/filmflowreviewendpoint.h
    controller/reviewcontroller.h
    network/request/paginationrequest.h
    entities/reviewsresult.h
    websocket/notificationws.h
    entities/notification.h
    entities/notificationreviewlike.h
    entities/typenotificationenum.h
    manager/notificationmanager.h
    controller/notificationcontroller.h
    network/endpoint/filmflownotificationendpoint.h
    entities/notificationsresult.h
    controller/reviewlikecontroller.h
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

find_package( Qt6 REQUIRED COMPONENTS Core Network Qml Gui Concurrent WebSockets)

target_link_libraries( ${LIBRARY_NAME} PUBLIC
    PRIVATE Qt6::Core
    PRIVATE Qt6::Network
    PRIVATE Qt6::Qml
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Concurrent
    PRIVATE Qt6::WebSockets
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

add_library(FF::Core ALIAS ${LIBRARY_NAME})

