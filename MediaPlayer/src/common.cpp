#include "common.h"
#include <QCoreApplication>
#include <QQmlContext>
#include <QObject>
#include <QMediaPlayer>
#include <QtQml/qqmlregistration.h>
#include "handler/media_handler.h"
#include "provider/image_provider.h"

MediaHandler mediaHandler;
ImageProvider imgP;
void configQmlContextBefore(QQmlApplicationEngine &engine)
{
    qmlRegisterType<MediaType>("fsoft", 1, 0, "MediaType");

    QString rcPath = "file:" + QCoreApplication::applicationDirPath() + "/";
    engine.rootContext()->setContextProperty("img_path", rcPath + "res/img/");
    engine.rootContext()->setContextProperty("ico_path", rcPath + "res/icon/");

    mediaHandler.complete();
    engine.rootContext()->setContextProperty("media_handler", &mediaHandler);
    
    engine.addImageProvider(QLatin1String("media"), &imgP);
}

void configQmlContextAfter(QQmlApplicationEngine &engine)
{
    QObject* root = engine.rootObjects().constFirst();
    QObject* musicPlayer = root->findChild<QObject*>("musicPlayer_Tzwa6AoQtWRfax7c6LgSwVmYVjLFjJNr");
    QMediaPlayer *mediaPlayer = root->findChild<QMediaPlayer*>("mediaPlayer_u8dmpJ0mWUdAGbRkuRolFiAgjnhOQART");
    QObject* videoOutput = root->findChild<QObject*>("videoOutput_4VCLnsY35vr7vmVkSTiQKIBe3uXERGfT");
    LOG << mediaPlayer;
    mediaHandler.initialize(mediaPlayer);
    mediaHandler.getPlayer()->setVideoOutput(videoOutput);
    QObject::connect(musicPlayer, SIGNAL(select(int)), &mediaHandler, SLOT(choose(int)));
    QObject::connect(musicPlayer, SIGNAL(play()), &mediaHandler, SLOT(play()));
    QObject::connect(musicPlayer, SIGNAL(pause()), &mediaHandler, SLOT(pause()));
    QObject::connect(musicPlayer, SIGNAL(prev()), &mediaHandler, SLOT(prev()));
    QObject::connect(musicPlayer, SIGNAL(next()), &mediaHandler, SLOT(next()));
    QObject::connect(&mediaHandler, &MediaHandler::currentChanged, &MediaHandler::play);
}
