import QtQuick
import QtQuick.Controls
import Qt5Compat.GraphicalEffects

Rectangle{
    id: middleBarId
    color: "#121E2E"//"#121E2E" - "#0066CC"
    radius: 10
    ListView {
        id: listViewId
        anchors.fill: parent
        model: ["5", "4", "3", "2", "1", "Off"]
        interactive: false  // Vô hiệu hóa cuộn và lướt
        Component.onCompleted: {
            climateEngine.adjustFanLevel(3);
        }

        delegate: Rectangle {
            id: rectItem
            height:  listViewId.width
            width: height //listViewId.height * .15
            color:  "transparent"// "#121E2E"
            border.width: 1
            border.color: "#070D19"//"#070D19"
            transformOrigin: Item.Center
            anchors.horizontalCenter: parent.horizontalCenter//.horizontalCenter

            Image {
                id: imageFan
                anchors.centerIn: parent
                visible: false  // Kiểm tra nếu là đường dẫn ảnh
                source:  "qrc:/assets/Icon/fan.png"
            }

            Text {
                id: fanLevelText
                anchors.centerIn: parent
                text: modelData
                font.pixelSize: 30
                color: "white"
            }


            MouseArea {
                anchors.fill: parent
                onClicked: {
                    listViewId.currentIndex = index
                    if(Number(modelData))
                        climateEngine.adjustFanLevel(Number(modelData))
                    else climateEngine.adjustFanLevel(Number(0))
                }
            }
            // States
            states: [
                State {
                    name: "enlarged" // Mở rộng
                    when: ( climodel.levelFan === Number(modelData) && climodel.levelFan !== 0)
                    PropertyChanges {
                        target: rectItem
                        width: middleBarId.width + 25
                        height: middleBarId.width - 10
                        radius: 5
                        color: "white"
                    }

                    PropertyChanges {
                        target: imageFan
                        visible: true
                    }

                    PropertyChanges {
                        target: fanLevelText
                        visible: false
                    }
                },
                State {
                    name: "off"
                    when: ( climodel.levelFan === 0 && modelData === "Off")
                    PropertyChanges {
                        target: rectItem
                        width: middleBarId.width + 25
                        height: middleBarId.width - 10
                        radius: 5
                        color: "white"
                    }

                    PropertyChanges {
                        target: imageFan
                        visible: false
                    }

                    PropertyChanges {
                        target: fanLevelText
                        visible: true
                        color : "black"
                        font.pixelSize : 30
                        font.bold: true
                    }
                },

                State {
                    name: "normal"
                    when: (climodel.levelFan !== Number(modelData))
                    PropertyChanges {
                        target: rectItem
                        width: listViewId.width
                        height: listViewId.width
                        anchors.horizontalCenter: parent.horizontalCenter
                        radius: 0
                        color: "transparent"
                    }
                    PropertyChanges {
                        target: imageFan
                        visible: false
                    }
                    PropertyChanges {
                        target: fanLevelText
                        visible: true
                        color : "white"
                    }
                }
            ]
            // Transitions
            transitions: [
                Transition {
                    from: "normal"
                    to: "enlarged"
                    reversible: true
                    NumberAnimation {
                        properties: "width,height"
                        duration: 300
                    }
                },
                Transition {
                    from: "normal"
                    to: "off"
                    reversible: true
                    NumberAnimation {
                        properties: "width,height"
                        duration: 300
                    }
                }
            ]
        }
    }
}



