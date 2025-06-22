set( MODULE_NAME Theme )

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
)
