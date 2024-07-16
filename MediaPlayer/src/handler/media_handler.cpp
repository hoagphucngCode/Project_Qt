#include "media_handler.h"
#include "src/common.h"
#include "src/provider/image_provider.h"
#include "src/utils/tagmeta.h"
#include <QCoreApplication>
#include <random>
#include <algorithm>

MediaHandler::MediaHandler(QObject *parent)
    : QObject{parent}, m_player(nullptr)
{
    m_type = MediaType::AUDIO;
    m_audioOutput = new QAudioOutput;
}

MediaHandler::~MediaHandler()
{
    m_audioOutput->deleteLater();
}

QList<MediaObject> MediaHandler::mediaMetaData(QString path)
{
    if(path.endsWith("/music"))
        return audioObject(path);
    else if(path.endsWith("/video"))
        return videoObject(path);
    return QList<MediaObject>();
}

#define INDEX_CON index < 0 || index > mediaList.count()
void MediaHandler::shuffle(QList<MediaObject> &mediaList)
{
    int index = currentIndex[MediaType::AUDIO];
    MediaObject obj;
    if(!(INDEX_CON))
        obj = mediaList.takeAt(index);

    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(mediaList.begin(), mediaList.end(), g);
    if(!(INDEX_CON))
        mediaList.prepend(obj);

}

MediaObject MediaHandler::getMedia(QList<MediaObject> objs, int &id)
{
    int i = 0;
    foreach(MediaObject obj, objs)
    {
        if(obj.id == id)
        {
            id = i;
            return obj;
        }
        i++;
    }
    return {};
}

int MediaHandler::type()
{
    return m_type;
}

void MediaHandler::setType(int type)
{
    m_type = type;
    chooseIndex(m_type == MediaType::AUDIO ? audios : videos, currentIndex[m_type]);
    emit typeChanged(type);
}

qint64 MediaHandler::duration() const
{
    // LOG << m_current.duration;
    return m_current.duration;
}

QString MediaHandler::image() const
{
    return m_current.image;
}

QString MediaHandler::name() const
{
    return m_current.name;
}

QString MediaHandler::artist() const
{
    return m_current.artist;
}

int MediaHandler::year() const
{
    return m_current.year;
}

qint64 MediaHandler::position() const
{
    if(!m_player)
        return 0;
    return m_player->position();
}

void MediaHandler::setPosition(qint64 position)
{
    if(!m_player)
        return ;
    m_player->setPosition(position);
}

int MediaHandler::l_index() const
{
    return currentIndex[m_type];
}

bool MediaHandler::isShuffle() const
{
    return m_isShuffle;
}

QSize MediaHandler::size() const
{
    return m_videoSize;
}

void MediaHandler::complete()
{
    mediaPath = QCoreApplication::applicationDirPath() + "/res/media";
    audio_org = audios = mediaMetaData(mediaPath + "/music");
    videos = mediaMetaData(mediaPath + "/video");
    // if(allowShuffle)
    //     shuffle(objs, current);
    // foreach(MediaObject obj, objs) {
    //     appending(obj.name, obj.artist, obj.year, obj.image, obj.sound, obj.duration);
    //     // LOG << obj.duration;
    // }
}

void MediaHandler::initialize(QMediaPlayer *mediaPlayer)
{
    m_player = mediaPlayer;
    m_player->setAudioOutput(m_audioOutput);

    connect(m_player, &QMediaPlayer::mediaStatusChanged, this, &MediaHandler::mediaStatusChanged);
}

void MediaHandler::push(QList<MediaObject> objs)
{
    foreach(MediaObject obj, objs) {
        appending(obj.id, obj.name, obj.artist, obj.year, obj.image, obj.duration);
        // LOG << obj.duration;
    }
    emit completeAppending();
}

void MediaHandler::chooseIndex(QList<MediaObject> objs, int index)
{
    currentIndex[m_type] = index;
    if(currentIndex[m_type] < 0)
        currentIndex[m_type] = objs.count() - 1;
    else if(currentIndex[m_type] >= objs.count())
        currentIndex[m_type] = 0;
    m_current = objs[currentIndex[m_type]]; 
    m_player->setSource(m_current.sound);
    emit currentChanged();
}

QMediaPlayer *MediaHandler::getPlayer()
{
    if(!m_player)
        return nullptr;
    return m_player;
}

void MediaHandler::request()
{
    if(m_type == MediaType::AUDIO)
        push(audios);
    else if(m_type == MediaType::VIDEO)
        push(videos);
}

bool MediaHandler::isPlaying()
{
    if(!m_player)
        return false;
    return m_player->playbackState() == QMediaPlayer::PlaybackState::PlayingState;
}

void MediaHandler::toggleShuffle()
{
    if(m_type == MediaType::AUDIO) {
        m_isShuffle = !m_isShuffle;
        if(m_isShuffle)
        {
            shuffle(audios);
            emit typeChanged(MediaType::AUDIO);
            currentIndex[MediaType::AUDIO] = 0;
            emit currentChanged();
        } else {
            MediaObject obj = audios[currentIndex[MediaType::AUDIO]];
            audios = audio_org;
            emit typeChanged(MediaType::AUDIO);
            choose(obj.id, false);
        }
        emit shuffleChanged(m_isShuffle);
    }
}

void MediaHandler::play()
{
    if(currentIndex[m_type] < 0)
        chooseIndex(m_type == MediaType::AUDIO ? audios : videos, currentIndex[m_type] + 1);
    m_player->play();
}

void MediaHandler::pause()
{
    m_player->pause();
}

void MediaHandler::prev()
{
    chooseIndex(m_type == MediaType::AUDIO ? audios : videos, currentIndex[m_type] - 1);
}

void MediaHandler::next()
{
    chooseIndex(m_type == MediaType::AUDIO ? audios : videos, currentIndex[m_type] + 1);
}

void MediaHandler::mediaStatusChanged(QMediaPlayer::MediaStatus status)
{
    if(status == QMediaPlayer::EndOfMedia)
        next();
}

void MediaHandler::fileMetaData(QMediaMetaData metaData)
{
    m_videoSize = metaData[QMediaMetaData::Resolution].toSize();
    emit sizeChanged();
}

void MediaHandler::choose(int id, bool changeSource)
{
    MediaObject obj;
    if(m_type == MediaType::AUDIO)
        obj = getMedia(audios, id);
    else if(m_type == MediaType::VIDEO)
        obj = getMedia(videos, id);
    if(changeSource)
        m_player->setSource(obj.sound);
    m_current = obj;
    currentIndex[m_type] = id;
    emit currentChanged();
}