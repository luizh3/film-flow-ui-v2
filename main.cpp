#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QDebug>
#include <QDirIterator>
#include <QFontDatabase>
#include <QQuickStyle>
#include <QTranslator>

#include <core/entities/movieinformation.h>
#include <core/entities/typeprogramenum.h>
#include <core/manager/applicationmanager.h>

#include <QPixmapCache>

#include <ui/theme/factory/themecolorfactory.h>
#include <ui/theme/manager/themecolormanager.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("ui");

    ApplicationManager::instance().languageManager().intialize(&app, &engine);

    QQuickStyle::setStyle("Basic");

    qRegisterMetaType<MovieInformation*>("MovieInformation*");
    qRegisterMetaType<TypeProgram::TypeProgramEnum>("TypeProgramEnum");
    qmlRegisterUncreatableType<MovieInformation*>(
        "MovieInformation", 1, 0, "MovieInformation",
        "MovieInformation não pode ser criado no QML"
        );

    qmlRegisterSingletonInstance("ThemeColorManager",
                                 1,
                                 0,
                                 "ThemeColorManager",
                                 ThemeColorManager::instance());

    qmlRegisterUncreatableMetaObject(TypeProgram::staticMetaObject,
                                     "TypeProgramEnum",
                                     1,
                                     0,
                                     "TypeProgramEnum",
                                     "Access to enums & flags only");

    ThemeColorManager::instance()->setRoleType(ColorRole::ORANGE);
    ThemeColorManager::instance()->setTheme(ThemeColorFactory::getOrange());

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("film-flow-ui", "Main");

    QDir dir(":/fonts");
    for (const QString &file : dir.entryList(QDir::Files)) {
        QFontDatabase::addApplicationFont(":/fonts/" + file);
    }

    // qInfo() << engine.importPathList();

    // MovieController().login();

    return app.exec();
}
