#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QFontDatabase>
#include <QDirIterator>
#include <QQuickStyle>

#include <core/entities/movieinformation.h>

#include <core/entities/typeprogramenum.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("ui");

    QQuickStyle::setStyle("Basic");

    qRegisterMetaType<MovieInformation*>("MovieInformation*");
    qRegisterMetaType<TypeProgram::TypeProgramEnum>("TypeProgramEnum");
    qmlRegisterUncreatableType<MovieInformation*>(
        "MovieInformation", 1, 0, "MovieInformation",
        "MovieInformation não pode ser criado no QML"
        );

    qmlRegisterUncreatableMetaObject( TypeProgram::staticMetaObject, "TypeProgramEnum", 1, 0, "TypeProgramEnum", "Access to enums & flags only");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("film-flow-ui", "Main");

    // TODO this is for test, move to .qrc
    QStringList fonts = {"C:\\Users\\Luiz\\Downloads\\Poppins\\Poppins-Medium.ttf",
                         "C:\\Users\\Luiz\\Downloads\\Poppins\\Poppins-Regular.ttf",
                         "C:\\Users\\Luiz\\Downloads\\Poppins\\Poppins-Bold.ttf",
                         "C:\\Users\\Luiz\\Downloads\\Poppins\\Poppins-SemiBold.ttf"};

    for( QString name : fonts ) {
        QFontDatabase::addApplicationFont( name );
    }

    qInfo() << engine.importPathList();

    // MovieController().login();

    return app.exec();
}
