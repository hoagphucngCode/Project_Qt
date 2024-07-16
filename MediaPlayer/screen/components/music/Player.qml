import QtQuick
import Qt5Compat.GraphicalEffects
import QtMultimedia

Rectangle {
    id: mainPlayer
    property bool isPlaying: false
    property bool isShuffle: false
    signal ended();
    signal next();
    signal prev();
    signal shuffle(bool bShuffle);
    width: parent.width * 2 / 3
    height: parent.height
    anchors.left: parent.left
    color: 'transparent'
    
    MediaPlayer {
        id: mediaPlayer
        objectName: 'mediaPlayer_u8dmpJ0mWUdAGbRkuRolFiAgjnhOQART'
        onMetaDataChanged: () => {
            media_handler.fileMetaData(metaData);
        }
    }

    Rectangle {
        id: info
        width: parent.width
        height: parent.height - controller.height
        color: 'transparent'
        Row {
            x: 25
            anchors.verticalCenter: parent.verticalCenter
            spacing: 10
            visible: !media_handler.type
            Image {
                id: musicImage
                source: media_handler.image
                width: 300; height: 300
                fillMode: Image.PreserveAspectCrop
                layer.enabled: true
                layer.effect: OpacityMask {
                    maskSource: Item {
                        width: musicImage.width
                        height: musicImage.height
                        Rectangle {
                            width: parent.width
                            height: parent.height
                            radius: 20
                        }
                    }
                }
            }
            Column {
                anchors.verticalCenter: parent.verticalCenter
                width: info.width - 350
                Text { color: 'white'; text: media_handler.name; width: parent.width; elide: Text.ElideRight; font{pixelSize: 30; weight: 600} }
                Text { color: 'white'; text: media_handler.artist; width: parent.width; elide: Text.ElideRight; font{pixelSize: 23}}
                Text { color: '#aaaaaa'; text: media_handler.year ? `(${media_handler.year})` : ""; width: parent.width; elide: Text.ElideRight; font{pixelSize: 20}}
            }
        }
        Rectangle {
            color: 'transparent'
            visible: media_handler.type;
            anchors.fill: parent
            id: videoOutput

            VideoOutput {
                objectName: 'videoOutput_4VCLnsY35vr7vmVkSTiQKIBe3uXERGfT'
                anchors.fill: parent
                fillMode: VideoOutput.PreserveAspectFit
            }
        }
    }
    Connections {
        target: media_handler
        function onTypeChanged(type)
        {
            if (type) {
                fblur.source = videoOutput
            } else {
                fblur.source = superImage
            }
        }
    }

    Controller {
        id: controller
    }
}
