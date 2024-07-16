#ifndef MUSIC_HANDLER_H
#define MUSIC_HANDLER_H

#include <QObject>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QMediaMetaData>
#include <QSize>

struct MediaObject
{
    int id;
    QString name;
    QString artist;
    int year;
    QString image;
    QString sound;
    qint64 duration;
};
enum MediaType {
    AUDIO = 0,
    VIDEO
};

class MediaHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(qint64 duration READ duration NOTIFY currentChanged)
    Q_PROPERTY(QString image READ image NOTIFY currentChanged)
    Q_PROPERTY(QString name READ name NOTIFY currentChanged)
    Q_PROPERTY(QString artist READ artist NOTIFY currentChanged)
    Q_PROPERTY(int year READ year NOTIFY currentChanged)
    Q_PROPERTY(int index READ l_index NOTIFY currentChanged)
    Q_PROPERTY(qint64 position READ position WRITE setPosition NOTIFY positionChanged)
    Q_PROPERTY(bool isShuffle READ isShuffle NOTIFY shuffleChanged)
    Q_PROPERTY(QSize size READ size NOTIFY sizeChanged)
public:
    explicit MediaHandler(QObject *parent = nullptr);
    ~MediaHandler();
    void complete();
    void initialize(QMediaPlayer* mediaPlayer);
private:
    void push(QList<MediaObject> objs);
    void chooseIndex(QList<MediaObject> objs, int index);

public:
    Q_INVOKABLE void choose(int id, bool changeSource = true);
    Q_INVOKABLE QMediaPlayer* getPlayer();
    Q_INVOKABLE void request();
    Q_INVOKABLE bool isPlaying();
    Q_INVOKABLE void toggleShuffle();

public slots:
    void play();
    void pause();
    void prev();
    void next();
    void mediaStatusChanged(QMediaPlayer::MediaStatus status);
    void fileMetaData(QMediaMetaData metaData);

signals:
    void appending(int id, QString name, QString artist, int year, QString image, qint64 duration);
    void completeAppending();
private:
    QList<MediaObject> mediaMetaData(QString path);
    void shuffle(QList<MediaObject> &mediaList);
    static MediaObject getMedia(QList<MediaObject> objs, int &id);

public:
    int type();
    void setType(int type);

    qint64 duration() const;
    QString image() const;
    QString name() const;
    QString artist() const;
    int year() const;

    qint64 position() const;
    void setPosition(qint64 position);
    
    int l_index() const;
    bool isShuffle() const;

    QSize size() const;

signals:
    void currentChanged();
    void typeChanged(int type);
    void positionChanged(quint64 position);
    void shuffleChanged(bool isShuffle);
    void sizeChanged();
    
private:
    QString mediaPath;
    QList<MediaObject> audios, audio_org;
    QList<MediaObject> videos;
    int m_type;
    MediaObject m_current;
    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;
    QSize m_videoSize;
    int currentIndex[2] = {-1, 0};
    bool m_isShuffle = false;
};

#endif // MUSIC_HANDLER_H
