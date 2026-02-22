set( LIBRARY_NAME core )
set( MODULE_URI Core )

set(CMAKE_AUTOMOC ON)

set( SOURCES
    controller/applicationcontroller.cpp
    network/httpclient.cpp
    manager/integrationmanager.cpp
    model/entities/integration.cpp
    network/endpoint/authendpoint.cpp
    model/entities/user.cpp
    model/entities/session.cpp
    controller/authcontroller.cpp
    network/response/response.cpp
    network/request/signuprequest.cpp
    network/request/signinrequest.cpp
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
    controller/applicationcontroller.h
    network/httpclient.h
    manager/integrationmanager.h
    model/entities/integration.h
    network/endpoint/authendpoint.h
    model/entities/user.h
    model/entities/session.h
    controller/authcontroller.h
    network/response/response.h
    network/httpstatuscode.h
    network/request/signuprequest.h
    network/request/signinrequest.h
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
    ${LIBRARY_NAME} STATIC
)

target_sources( ${LIBRARY_NAME}
    PRIVATE ${SOURCES}
    PUBLIC FILE_SET HEADERS FILES ${HEADERS}
)

find_package( Qt6 REQUIRED COMPONENTS Core Network Concurrent WebSockets)

target_link_libraries(${LIBRARY_NAME}
    PUBLIC
        Qt6::Core
        Qt6::Network
        Qt6::Concurrent
        Qt6::WebSockets
)

target_include_directories(${LIBRARY_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>
        $<INSTALL_INTERFACE:include>
)

set_target_properties( ${LIBRARY_NAME} PROPERTIES POSITION_INDEPENDENT_CODE ON )

target_compile_definitions( ${LIBRARY_NAME} PUBLIC CORE_STATIC )

add_library(FF::Core ALIAS ${LIBRARY_NAME})

