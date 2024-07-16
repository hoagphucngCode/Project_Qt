import QtQuick
import QtQuick.Controls
import QtMultimedia
import '../../utils.js' as Utils
import fsoft

Rectangle {
    id: mainControl
    width: parent.width
    height: 150
    anchors.bottom: parent.bottom
    color: 'transparent';

    Slider {
        id: slider
        anchors.horizontalCenter: parent.horizontalCenter
        width: parent.width * 90 / 100
        enabled: !!media_handler.getPlayer().source
        height: 20
        from: 0
        to: mediaPlayer.duration
        value: mediaPlayer.position
        Connections {
            target: media_handler
            function onPositionChanged(val) {
                console.log(val);
            }
        }
        onMoved: {
            media_handler.position = (value)
        }
        handle: Rectangle {
            property int diameter: slider.pressed ? 25 : 20
            anchors.verticalCenter: parent.background.verticalCenter
            x: slider.visualPosition * (slider.availableWidth - width)
            y: slider.availableHeight / 2 - height / 2
            width: diameter
            height: diameter
            radius: diameter / 2
            color: 'white'
            Behavior on width {
                PropertyAnimation {
                    duration: 100
                }
            }
            Behavior on height {
                PropertyAnimation {
                    duration: 100
                }
            }
        }

        background: Rectangle {
            implicitWidth: 200
            height: 8
            color: "#888888"
            radius: 4
            Rectangle {
                width: slider.visualPosition * slider.width
                height: parent.height
                color: "white"
                radius: 4
            }
        }
    }
    
    Text {text: Utils.formatMilliseconds(slider.value); y: height; anchors.left: slider.left; color: 'white'}
    Text {text: Utils.formatMilliseconds(mediaPlayer.duration - slider.value); y: height; anchors.right: slider.right; color: 'white'}
    Rectangle {
        id: mainController;
        property bool isPlaying: false
        property bool isShuffle: false
        height: 100
        width: parent.width * 90 / 100
        anchors.bottom: parent.bottom;
        anchors.horizontalCenter: parent.horizontalCenter;
        color: 'transparent'
        // IconButton {
        //     width: 50
        //     src: ico_path + (parent.isShuffle ? 'shuffer_on.svg' : 'shuffer_off.svg')
        //     anchors.left: parent.left
        //     onClicked: {
        //         parent.isShuffle = !parent.isShuffle;
        //         mainControl.parent.shuffle(parent.isShuffle);
        //     }
        // }
        IconButton {
            width: 50
            src: ico_path + (!media_handler.type ? 'movie.svg' : 'music.svg')
            anchors.left: parent.left
            onClicked: {
                media_handler.type = !media_handler.type;

                /* setting */
            }
        }
        IconButton {
            width: 50
            src: ico_path + (!media_handler.type ? 'fullscreen_disabled.svg' : 'fullscreen.svg')
            anchors.right: parent.right
            onClicked: {
                console.log('full!');
            }
        }
        Row {
            id: row
            spacing: 10
            anchors.centerIn: parent;
            IconButton {
                width: 60
                src: ico_path + 'prev.svg'
                onClicked: {playlist.parent.prev()}
            }
            IconButton {
                src: ico_path + (mediaPlayer.playbackState === MediaPlayer.PlayingState ? 'pause.svg' : 'play.svg')
                onClicked: {
                    if (media_handler.isPlaying()) {
                        playlist.parent.pause();
                    } else {
                        playlist.parent.play();
                    }
                }
            }
            IconButton {
                width: 60
                src: ico_path + 'next.svg'
                onClicked: {playlist.parent.next()}
            }
        }
    }
}
