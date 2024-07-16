#undef QT_NO_DEBUG_OUTPUT
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "src/common.h"
#include <QtGlobal>
#include <iostream>
#include <QMediaPlayer>
#include "src/handler/media_handler.h"

extern MediaHandler mediaHandler;
int main(int argc, char *argv[])
{
	QGuiApplication app(argc, argv);
	QQmlApplicationEngine engine;

	configQmlContextBefore(engine);

	const QUrl url(QStringLiteral("qrc:/MediaPlayer/main.qml"));
	QObject::connect(
		&engine,
		&QQmlApplicationEngine::objectCreated,
		&app,
		[url](QObject *obj, const QUrl &objUrl)
		{
			if (!obj && url == objUrl)
				QCoreApplication::exit(-1);
			else {
				
			}
		},
		Qt::QueuedConnection);
	engine.load(url);
	configQmlContextAfter(engine);

	return app.exec();
}
