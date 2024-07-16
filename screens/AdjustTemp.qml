import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout{
    id: tempId
    required property int temp
    signal up()
    signal down()
    spacing: 30 // 50
    Image {
        id: increaseTempe
        width: 64
        height:  64
        source: mouseAreaUp.containsPress ? "qrc:/assets/Icon/arrow-up_gray.png" : "qrc:/assets/Icon/arrow-up.png"
        Layout.alignment: Qt.AlignHCenter
        MouseArea{
            id : mouseAreaUp
            anchors.fill: parent
            pressAndHoldInterval: 800
            onClicked: {
                tempId.up()
            }
            onPressAndHold: {
                timerUpTemp.running = true
            }
            onReleased: {
                timerUpTemp.running = false
            }
            Timer{
                id: timerUpTemp
                interval: 200
                repeat: true
                onTriggered: {
                    tempId.up()
                }
            }
        }



    }

    Text{
        id : textTemp
        text : temp
        font.pixelSize: 120 // 100
        color: "#CD5C64"
        Layout.alignment: Qt.AlignHCenter
        //Layout.leftMargin: 20
        font.weight: Font.Thin
        Text{
            anchors.left: textTemp.right
            text: "°"
            font.pixelSize: 60
            color: "#CD5C64"
        }
    }

    Image {
        id: down
        width: 64
        height:  64
        source: mouseAreaDown.containsPress ? "qrc:/assets/Icon/arrow-up_gray.png" : "qrc:/assets/Icon/arrow-up.png"
        Layout.alignment: Qt.AlignHCenter
        rotation: 180
        MouseArea{
            id : mouseAreaDown
            anchors.fill: parent
            pressAndHoldInterval: 800
            onClicked: {
                tempId.down()
            }
            onPressAndHold:{
                timerDownTemp.running = true
            }
            onReleased: {
                timerDownTemp.running = false
            }
            Timer{
                id: timerDownTemp
                interval: 150
                repeat: true
                onTriggered: {
                    tempId.down()
                }
            }
        }
    }

}
