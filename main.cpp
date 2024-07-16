#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtAppManCommon/logging.h>
#include <QtAppManLauncher/launchermain.h>
#include <QtAppManLauncher/dbusapplicationinterface.h>
#include <QtAppManLauncher/dbusnotification.h>
#include <QQmlContext>
#include <QDebug>
#include "climateengine.h"



int main(int argc, char *argv[])
{
    QtAM::Logging::initialize(argc, argv);
    QtAM::Logging::setApplicationId("climate");

    QtAM::LauncherMain::initialize();
    QGuiApplication app(argc, argv);
    QtAM::LauncherMain launcher;

    launcher.registerWaylandExtensions();
    launcher.loadConfiguration();
    launcher.setupLogging(false, launcher.loggingRules(), QString(), launcher.useAMConsoleLogger());
    launcher.setupDBusConnections();

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/climatescreen.qml"));

    qDebug() << "Main Climate";
    Climodel* climodel = new Climodel();
    engine.rootContext()->setContextProperty("climodel",climodel);

    ClimateEngine* climateEngine = new ClimateEngine(climodel);
    engine.rootContext()->setContextProperty("climateEngine",climateEngine);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    // Application interface for handling quit
    QtAM::DBusApplicationInterface iface(launcher.p2pDBusName(), launcher.notificationDBusName());
    iface.initialize();
    QObject::connect(&iface, &QtAM::DBusApplicationInterface::quit, [&iface] () {
        iface.acknowledgeQuit();
    });

    return app.exec();
}
