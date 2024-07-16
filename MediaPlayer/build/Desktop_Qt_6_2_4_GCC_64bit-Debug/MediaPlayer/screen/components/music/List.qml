import QtQuick
import QtMultimedia
import '../../utils.js' as Utils
Rectangle {
    id: listMain
    property int current: -1

    width: parent.width / 3
    height: parent.height
    anchors.right: parent.right
    color: '#88000000'
    states: [
        State {
            name: 'expanded'
            PropertyChanges {
                target: listMain
                width: parent.width / 3
            }
            PropertyChanges {
                target: playlistBtn
                x:30
                y:20
            }
            PropertyChanges {
                target: playlooptBtn
                x:90
                y:20
            }
             PropertyChanges {
                target: rectShuffle
                x:150
                y:20
            }
            PropertyChanges {
                target: flipIcon
                flip: false
            }
        },
        State {
            name: 'collapsed'
            PropertyChanges {
                target: listMain
                width: 0
            }

            PropertyChanges {
                target: playlistBtn
                x: parent.width - playlistBtn.width - 30


            }
            PropertyChanges {
                target: playlooptBtn
                x: parent.width - playlooptBtn.width - 30
                y: playlistBtn.y + playlistBtn.height + 20
            }
             PropertyChanges {
                target: rectShuffle
                x: parent.width - rectShuffle.width - 30
                y: playlooptBtn.y + playlooptBtn.height + 20
            }
            PropertyChanges {
                target: flipIcon
                flip: true
            }
        }
    ]
    transitions: [
        Transition {
            reversible: true
            ParallelAnimation {
                NumberAnimation {
                    properties: "width"
                    duration: 750
                    easing.type: Easing.OutExpo
                }
                NumberAnimation {
                    properties: "x"
                    duration: 750
                    easing.type: Easing.OutExpo
                }
                NumberAnimation {
                    properties: "y"
                    duration: 750
                    easing.type: Easing.OutExpo
                }
            }
        }
    ]
    Rectangle {
        id: borderLeft
        width: 2
        height: parent.height;
        anchors.left: parent.left
        gradient: Gradient {
            orientation: Gradient.Vertical
            GradientStop { position: 0; color: '#00ffffff' }
            GradientStop { position: .45; color: '#44ffffff' }
            GradientStop { position: .55; color: '#44ffffff' }
            GradientStop { position: 1; color: '#00ffffff' }
        }
    }

    Rectangle {
        id: playlistBtn
        width: 50
        height: 50
        x: 30
        y: 20
        color: 'transparent'

        IconButton {
            id: flipIcon
            width: 40
            flip: false
            anchors{
                centerIn: parent
            }
            src: ico_path + 'playlist.svg'
            onClicked: {
                listMain.state = listMain.state === 'collapsed' ? 'expanded' : 'collapsed'
            }
        }
    }

    Rectangle {
        id: playlooptBtn
        width: 50
        height: 50
        x: 90
        y: 20
        color: 'transparent'

        IconButton {
            width: 40
            anchors{
                centerIn: parent
            }

            property int loopState: 0

            src: ico_path + 'repeat_off.svg'

            onClicked: {
                console.log("Loop button clicked, loop state: ", loopState)
                loopState = (loopState + 1) % 3
                switch(loopState) {
                    case 0:
                        src: ico_path + 'repeat_off.svg'
                        break
                    case 1:
                        src: ico_path + 'repeat.svg'
                        break
                    case 2:
                        src: ico_path + 'repeat_one.svg'
                        break
                }
            }
        }
    }

    Rectangle {
        id: rectShuffle
        width: 50
        height: 50
        x: 150
        y: 20
        color: 'transparent'
        // anchors {
        //     top: parent.top
        //     left: playlistBtn.right
        //     topMargin: 10
        //     leftMargin: 10
        // }
        IconButton {
            width: 40
            anchors{
                centerIn: parent
            }
            src: ico_path + (media_handler.isShuffle ? 'shuffer_on.svg' : 'shuffer_off.svg')
            anchors.left: parent.left
            onClicked: {
                media_handler.toggleShuffle();
            }
        }

    }
    ListModel {
        id: musicModel
    }

    ListView {
        id: musicList
        anchors {
            top: playlistBtn.bottom
            bottomMargin: 20
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
        clip: true
        y: 10
        currentIndex: -1
        model: musicModel
        delegate: Rectangle {
            id: elementRect
            width: musicList.width
            height: 75
            color: 'transparent'
            Row {
                width: parent.width - 25
                x: 12.5
                spacing: 10
                anchors.verticalCenter: parent.verticalCenter
                clip: true
                // Image {
                //     width: 100
                //     height: 100
                //     source: image
                //     fillMode: Image.PreserveAspectCrop
                // }
                Text {
                    text: index + 1
                    color: 'white'
                    anchors.verticalCenter: parent.verticalCenter
                }
                Column {
                    width: parent.width - 10;
                    anchors.verticalCenter: parent.verticalCenter
                    Text {
                        text: name; elide: Text.ElideRight; width: parent.width; font{pixelSize: 20; weight: 600}
                        color:"#3f5cb0"
                        font.bold: true
                    }
                    Text { color: 'white'; text: artist; elide: Text.ElideRight; width: parent.width; }
                }
            }

            Rectangle {
                id: bottomBorder
                width: parent.width
                height: 2
                anchors.top: parent.bottom
                gradient: Gradient {
                    orientation: Gradient.Horizontal
                    GradientStop { position: 0; color: '#00ffffff' }
                    GradientStop { position: .49; color: '#44ffffff' }
                    GradientStop { position: .51; color: '#44ffffff' }
                    GradientStop { position: 1; color: '#00ffffff' }
                }
            }
            MouseArea {
                property bool isPressed: false
                property bool isHovered: false
                anchors.fill: parent
                cursorShape: Qt.PointingHandCursor
                hoverEnabled: true
                onEntered: {
                    parent.color = '#44ffffff';
                }
                onExited: {
                    parent.color = 'transparent';
                }
                onPressed: {
                    parent.color = '#88ffffff';
                }
                onReleased: {
                    parent.color = '#44ffffff';
                }
                onClicked: {
                    listMain.parent.select(id);
                }
            }
            Behavior on color {
                PropertyAnimation {duration: 200}
            }
        }
        highlight: Rectangle {
            color: "#33ffffff"
            opacity: 1
        }

        highlightFollowsCurrentItem: true
        highlightMoveDuration: 0
    }

    Connections {
        target: media_handler
        function onAppending(id, name, artist, year, image, duration) {
            var obj = {id, name, artist, year, image, duration};
            musicModel.append(obj)
            // console.log(obj);
        }
        function onTypeChanged(val) {
            clear();
            media_handler.request();
        }
        function onCompleteAppending() {
            musicList.currentIndex = (media_handler.index);
        }
        function onCurrentChanged() {
            musicList.currentIndex = (media_handler.index);
        }
    }
    function clear()
    {
        musicModel.clear()
    }
}
