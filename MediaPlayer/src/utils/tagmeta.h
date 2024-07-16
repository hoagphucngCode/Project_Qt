#ifndef TAGMETA_H
#define TAGMETA_H

#include "src/handler/media_handler.h"
#include "src/provider/image_provider.h"
#include "src/common.h"
#include <QString>
#include <QList>
#include <QCoreApplication>
#include <QDirIterator>

extern ImageProvider imgP;
QList<MediaObject> audioObject(QString path);
QList<MediaObject> videoObject(QString path);

#endif // !TAGMETA_H