#include "tagmeta.h"
#include <QImage>
#include <QBuffer>
#include <QByteArray>
#include <taglib/fileref.h>
#include <taglib/mpegfile.h>
#include <taglib/mp4file.h>
#include <taglib/id3v2tag.h>
#include <taglib/attachedpictureframe.h>

QList<MediaObject> audioObject(QString path)
{
    QString resPath = QCoreApplication::applicationDirPath() + "/res";
	QDir dir(path);
    QList<MediaObject> objs;
    QStringList files = dir.entryList(QStringList() << "*", QDir::Files);
    int index = 0;
    foreach(QString filename, files) {
        QString s = path + '/' + filename;
        TagLib::MPEG::File file(s.toStdString().c_str());
        if(file.isValid()) {
            TagLib::ID3v2::Tag *tag = file.ID3v2Tag();
            QString title = QString::fromStdWString(tag->title().toCWString());
            if(title.length() == 0)
                title = QString::fromStdWString(filename.toStdWString().substr(0, filename.lastIndexOf('.')).c_str());
            // LOG << title;
            QString artist = QString::fromStdWString(tag->artist().toCWString());
            int year = tag->year();
            QImage imageSrc;
            imageSrc.load(QUrl("file:" + resPath + "/img/music_img.png").toLocalFile());
            TagLib::ID3v2::FrameList frameList = tag->frameList("APIC");
            if(!frameList.isEmpty()) {
                TagLib::ID3v2::AttachedPictureFrame *coverImage = static_cast<TagLib::ID3v2::AttachedPictureFrame *>(frameList.front());
                imageSrc.loadFromData((const uchar *) coverImage->picture().data(), coverImage->picture().size());
                QByteArray byteArray;
                QBuffer buffer(&byteArray);
                buffer.open(QIODevice::WriteOnly);
                imageSrc.save(&buffer, "PNG"); // writes image into byteArray in PNG format
            }
            // Using base64 string is more simple but also risk memory and takes more time to load
            // So, using a complex way that have higher efficient than using a simple way
            // ImageProvider has no memory disavantages
            QString img = imgP.addImage(QString("img_index_") + QString::number(index), imageSrc);
            objs.append(MediaObject{index, title, artist, year, "image://media/" + img, "file://" + s, file.audioProperties()->lengthInMilliseconds()});
            // LOG << file.audioProperties()->lengthInMilliseconds();
            index++;
        } else LOG << "invalid";
    }
    return objs;

}

QList<MediaObject> videoObject(QString path)
{
    QString resPath = QCoreApplication::applicationDirPath() + "/res";
	QDir dir(path);
    QList<MediaObject> objs;
    QStringList files = dir.entryList(QStringList() << "*", QDir::Files);
    int index = 0;
    foreach(QString filename, files) {
        QString s = path + '/' + filename;
        TagLib::MP4::File file(s.toStdString().c_str());
        if(file.isValid()) {
            TagLib::MP4::Tag *tag = file.tag();
            QString title = QString::fromStdWString(tag->title().toCWString());
            if(title.length() == 0)
                title = QString::fromStdWString(filename.toStdWString().substr(0, filename.lastIndexOf('.')).c_str());
            // LOG << title;
            QString artist = QString::fromStdWString(tag->artist().toCWString());
            int year = tag->year();
            TagLib::MP4::Properties *props = file.audioProperties();
            objs.append(MediaObject{index, title, artist, year, "", "file://" + s, props->lengthInMilliseconds()});
            // LOG << file.audioProperties()->lengthInMilliseconds();
            index++;
        }
    }
    return objs;
}
