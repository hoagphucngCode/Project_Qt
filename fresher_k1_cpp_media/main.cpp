#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtAppManCommon/logging.h>
#include <QtAppManLauncher/launchermain.h>
#include <QtAppManLauncher/dbusapplicationinterface.h>
#include <QtAppManLauncher/dbusnotification.h>
#include <QApplication>
#include <QPushButton>
#include <QDialog>
#include <QVBoxLayout>

int main(int argc, char *argv[])
{
    QtAM::Logging::initialize(argc, argv);
    QtAM::Logging::setApplicationId("climate");

    QtAM::LauncherMain::initialize();
    // QGuiApplication app(argc, argv);
    QApplication app(argc, argv);
    QtAM::LauncherMain launcher;

    launcher.registerWaylandExtensions();
    launcher.loadConfiguration();
    launcher.setupLogging(false, launcher.loggingRules(), QString(), launcher.useAMConsoleLogger());
    launcher.setupDBusConnections();

    // QWidget window;
    // QVBoxLayout layout(&window);

    // // Popup using application manager window property
    // QPushButton button1(QStringLiteral("Click to open/close a popup"));
    // button1.setStyleSheet(QStringLiteral("QPushButton { background-color : limegreen; font-size: 36px; }"));
    // layout.addWidget(&button1);

    // QDialog *popup1 = new QDialog(&window);
    // (new QPushButton(QStringLiteral("I'm a popup!"), popup1))->resize(340, 140);
    // popup1->setStyleSheet(QStringLiteral("QPushButton { background-color : limegreen; color : white; font-size: 24px; }"));
    // QObject::connect(&button1, &QPushButton::clicked, [&popup1, &launcher] () {
    //     popup1->setVisible(!popup1->isVisible());
    //     launcher.setWindowProperty(popup1->windowHandle(), QStringLiteral("type"), QStringLiteral("pop-up"));
    // });

    // // Notification
    // QPushButton button2(QStringLiteral("Click to open a notification"));
    // button2.setStyleSheet(QStringLiteral("QPushButton { background-color : darkgrey; font-size: 36px; }"));
    // layout.addWidget(&button2);

    // QtAM::DBusNotification *notification = QtAM::DBusNotification::create(&app);
    // notification->setSummary(QStringLiteral("I'm a notification"));
    // QObject::connect(&button2, &QPushButton::clicked, notification, &QtAM::DBusNotification::show);


    QQmlApplicationEngine engine;
    const QUrl url("qrc:/media/screens/mdascreen.qml");
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                    &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    // Application interface for handling quit
    QtAM::DBusApplicationInterface iface(launcher.p2pDBusName(), launcher.notificationDBusName());
    iface.initialize();
    QObject::connect(&iface, &QtAM::DBusApplicationInterface::quit, [&iface] () {
        iface.acknowledgeQuit();
    });

    // app.processEvents();
    // window.showNormal();

    return app.exec();
}
