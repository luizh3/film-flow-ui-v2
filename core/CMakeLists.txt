set( LIBRARY_NAME core )
set( MODULE_URI Core )

set(CMAKE_AUTOMOC ON)

set( SOURCES
    controller/moviecontroller.cpp
    controller/applicationcontroller.cpp
    network/httpclient.cpp
    singleton/integrationmanager.cpp
    model/entities/integration.cpp
    network/endpoint/authendpoint.cpp
    model/entities/user.cpp
    model/entities/session.cpp
    controller/authcontroller.cpp
    network/response/response.cpp
    network/request/signuprequest.cpp
    network/request/signinrequest.cpp
    validator/emailvalidator.cpp
    validator/rangevalidator.cpp
    validator/ffvalidator.cpp
    validator/passwordvalidator.cpp
    network/endpoint/filmflowconfigendpoint.cpp
    network/endpoint/filmflowendpoint.cpp
    manager/applicationmanager.cpp
    model/config/configs.cpp
    model/config/sectionsconfig.cpp
    model/config/programconfig.cpp
    network/endpoint/filmflowsectionendpoint.cpp
    network/request/sectionrequest.cpp
    controller/sectioncontroller.cpp
    model/entities/movieinformation.cpp
    model/result/searchmoviesresult.cpp
    model/entities/genre.cpp
    model/result/paginationresult.cpp
    helper/taskrunhelper.cpp
    network/endpoint/filmflowmultiendpoint.cpp
    network/request/multirequest.cpp
    controller/multicontroller.cpp
    network/request/multidetailsrequest.cpp
    manager/languagemanager.cpp
    network/endpoint/filmflowreviewendpoint.cpp
    controller/reviewcontroller.cpp
    model/entities/review.cpp
    model/result/reviewsresult.cpp
    network/request/paginationrequest.cpp
    websocket/notificationws.cpp
    model/entities/notification.cpp
    model/entities/notificationreviewlike.cpp
    manager/notificationmanager.cpp
    controller/notificationcontroller.cpp
    network/endpoint/filmflownotificationendpoint.cpp
    model/result/notificationsresult.cpp
    controller/reviewlikecontroller.cpp
)

set( HEADERS
    controller/moviecontroller.h
    controller/applicationcontroller.h
    network/httpclient.h
    singleton/integrationmanager.h
    model/entities/integration.h
    network/endpoint/authendpoint.h
    model/entities/user.h
    model/entities/session.h
    controller/authcontroller.h
    network/response/response.h
    network/httpstatuscode.h
    network/request/signuprequest.h
    network/request/signinrequest.h
    validator/emailvalidator.h
    validator/rangevalidator.h
    validator/ffvalidator.h
    validator/passwordvalidator.h
    helper/regex/regexhelper.h
    network/endpoint/filmflowconfigendpoint.h
    network/endpoint/filmflowendpoint.h
    manager/applicationmanager.h
    model/config/configs.h
    model/config/sectionsconfig.h
    model/config/programconfig.h
    model/entities/genre.h
    model/enum/typeprogramenum.h
    network/endpoint/filmflowsectionendpoint.h
    network/request/sectionrequest.h
    controller/sectioncontroller.h
    model/result/paginationresult.h
    model/entities/movieinformation.h
    model/result/searchmoviesresult.h
    helper/taskrunhelper.h
    network/endpoint/filmflowmultiendpoint.h
    network/request/multirequest.h
    controller/multicontroller.h
    network/request/multidetailsrequest.h
    manager/languagemanager.h
    model/entities/review.h
    network/endpoint/filmflowreviewendpoint.h
    controller/reviewcontroller.h
    network/request/paginationrequest.h
    model/result/reviewsresult.h
    websocket/notificationws.h
    model/entities/notification.h
    model/entities/notificationreviewlike.h
    model/enum/typenotificationenum.h
    manager/notificationmanager.h
    controller/notificationcontroller.h
    network/endpoint/filmflownotificationendpoint.h
    model/result/notificationsresult.h
    controller/reviewlikecontroller.h
    core_global.h
)

add_library(
    ${LIBRARY_NAME} SHARED
)

qt_add_qml_module( ${LIBRARY_NAME}
  URI ${MODULE_URI}
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

#TODO Review this to use only CMAKE_CURRENT_SOURCE_DIR, as QML_ELEMENT cannot find it when used this way for now.
target_include_directories(${LIBRARY_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/model
  ${CMAKE_CURRENT_SOURCE_DIR}/model/entities
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

