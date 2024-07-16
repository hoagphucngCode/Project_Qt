import QtQuick
import Qt5Compat.GraphicalEffects
import 'screen/features'
import 'screen/utils.js' as Utils

Window {
    id: fixedWindow
    visible: true
    width: 1080
    height: 610
    flags: Qt.Window | Qt.FramelessWindowHint
    
	Rectangle {
        id: mainHome
        objectName: 'mainHome'
        property bool restate: false;
        property bool bkg: false;
        width: parent.width
        height: parent.height
        states: [
            State {
                name: 'bkgi1'
                PropertyChanges {
                    target: backgroundImg
                    opacity: 1
                }
                PropertyChanges {
                    target: backgroundImg2
                    opacity: 0
                }
            },
            State {
                name: 'bkgi2'
                PropertyChanges {
                    target: backgroundImg
                    opacity: 0
                }
                PropertyChanges {
                    target: backgroundImg2
                    opacity: 1
                }
            }
        ]
        Component.onCompleted: {
            mainHome.state = 'started';
        }
        Item {
            id: superImage
            anchors.fill: parent
            Image {
                id: backgroundImg
                width: parent.width
                height: parent.height
                fillMode: Image.PreserveAspectCrop
                source: img_path + "bkg_music.png"
                opacity: 1
                Behavior on opacity {
                    PropertyAnimation { duration: 500 }
                }
            }
            Image {
                id: backgroundImg2
                width: parent.width
                height: parent.height
                fillMode: Image.PreserveAspectCrop
                source: img_path + "bkg_music.png"
                opacity: 0
                Behavior on opacity {
                    PropertyAnimation { duration: 500 }
                }
            }
        }
        function hyperChangeImage(src) {
            if(bkg) {
                backgroundImg.source = src;
                state = 'bkgi1';
            } else {
                backgroundImg2.source = src;
                state = 'bkgi2';
            }
            bkg = !bkg;
        }
        Rectangle {
            width: mainHome.width
            height: mainHome.height

            FastBlur {
                id: fblur
                anchors.centerIn: parent
                width:0
                height: 0
                source: superImage
                radius: 64
                transparentBorder: true
            }
            Rectangle {
                id: blurFade
                anchors.fill: parent
                color: '#44000000'
                MusicPlayer {
                    id: mp
                    opacity: 1
                }
            }
        }

        Connections {
            target: media_handler
            function onCurrentChanged()
            {
                mainHome.hyperChangeImage(media_handler.image);
            }
            function onSizeChanged()
            {
                const width = (media_handler.size.width);
                const height = (media_handler.size.height);
                if(width > 0 && height > 0)
                {
                    const size = Utils.fitting(media_handler.size, Qt.size(fixedWindow.width, fixedWindow.height))
                    // console.log(size);
                    fblur.width = 3 * size.width - fixedWindow.width;
                    fblur.height = 3 * size.height - fixedWindow.height;
                } else {
                    fblur.width = fblur.parent.width
                    fblur.height = fblur.parent.height;
                }
            }
        }
    }
}
