import QtQuick 2.15
import QtMultimedia
import '../components/music'

Rectangle {
    objectName: "musicPlayer_Tzwa6AoQtWRfax7c6LgSwVmYVjLFjJNr"
    property int current: -1
    property bool isMovieMode: false
    signal changed(string img);
    signal select(int id);
    signal play();
    signal pause();
    signal prev();
    signal next();
    anchors.centerIn: parent
    width: 1080
    height: parent.height;
    color: '#88000000'
    clip: true

    Component.onCompleted: {
        media_handler.request();
    }

    Player {
        id: player
        anchors.right: playlist.left
        onEnded: {
            playlist.next();
        }
        onNext: {
            playlist.next();
        }
        onPrev: {
            playlist.prev();
        }
        onShuffle: (bShuffle) => {
            const oldCurr = playlist.current;
            playlist.current = -1;
            playlist.clear();
            music_handler.complete(bShuffle, oldCurr);
            if(oldCurr > -1)
                playlist.current = 0
        }
    }
    List {
        id: playlist;
        current: parent.current
    }
}
