import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id : root
    color: "#070D19"
    readonly property int spaceHeight: 5

    RowLayout{
        id: rowId
        anchors.fill: root
        spacing: -5

        // ColumnFirst
        ColumnLayout{
            id : columnfirst
            Layout.preferredWidth: parent.width * .35
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop | Qt.AlignBottom
            Layout.leftMargin: 30

            AdjustTemp{
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.topMargin: 50 // 50 - 70
                temp: climodel.tempFront
                onUp: {
                    climateEngine.upTempFront()
                }
                onDown: {
                    climateEngine.downTempFront()
                }
            }
            // spacing
            Item{
                id : space1Id
                Layout.preferredHeight: root.spaceHeight
            }

            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 100
                spacing: 100

                HeatSeats{
                    id: heatSeatsFont
                    soureImage_on:"qrc:/assets/Icon/heated_seats_white.png"
                    soureImage_off:"qrc:/assets/Icon/heated_seats_gray.png"
                    leftRight: "left"
                    levelHeat: climodel.levelHeatSeatFront
                    onLevelChange:{
                        console.log("HeatSeat Level: " + heatSeatsFont.level)
                        climateEngine.adjustHeatSeatLevelFront(heatSeatsFont.level)
                    }
                }

                // front Window Defroster
                Image{
                    id: frontWinDefroster
                    width: 50
                    height: 50
                    sourceSize.width: width
                    sourceSize.height: height
                    property bool checked: false
                    fillMode: Image.PreserveAspectFit
                    // front Windown Defroster - bool
                    source: climodel.frontWinDefroster ? "qrc:/assets/Icon/heater_white.png" : "qrc:/assets/Icon/heater_gray.png"
                    Text {
                        text: qsTr("Front")
                        font.pixelSize: 13
                        anchors.top: frontWinDefroster.bottom
                        anchors.topMargin: -8
                        font.family: "Arial"
                        font.weight: Font.ExtraBold
                        anchors.horizontalCenter: frontWinDefroster.horizontalCenter
                        color : frontWinDefroster.checked ? "white" : "gray"
                    }

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            frontWinDefroster.checked = !frontWinDefroster.checked
                            climateEngine.controlFrontWindowDefroster(frontWinDefroster.checked)
                        }
                    }
                }

                // Rear Window Defroster
                Image{
                    id: rearWinDefroster
                    width: 50
                    height: 50
                    sourceSize.width: width
                    sourceSize.height: height
                    property bool checked: false
                    fillMode: Image.PreserveAspectFit
                    source: climodel.rearWindDefroster ? "qrc:/assets/Icon/Rear_white.png" : "qrc:/assets/Icon/Rear_gray.png"
                    Text {
                        text: qsTr("Rear")
                        font.pixelSize: 13
                        anchors.top: rearWinDefroster.bottom
                        anchors.topMargin: -8
                        font.family: "Arial"
                        font.weight: Font.ExtraBold
                        anchors.horizontalCenter: rearWinDefroster.horizontalCenter
                        color : rearWinDefroster.checked ? "white" : "gray"
                    }

                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            rearWinDefroster.checked = !rearWinDefroster.checked
                            climateEngine.controlRearWindowDefroster(rearWinDefroster.checked)
                        }
                    }
                }
            }
        }

        // MiddelBar
        MiddleBar{
            id : middleBarId
            Layout.preferredWidth: 92 //parent.width * .10 - 110
            Layout.preferredHeight: root.height * .87 //.88
            Layout.alignment:  Qt.AlignTop | Qt.AlignHCenter
            Layout.topMargin: 20
        }

        // ColumnSencond
        ColumnLayout{
            id : columnSecond
            Layout.preferredWidth: parent.width * .35
            Layout.alignment: Qt.AlignRight | Qt.AlignTop | Qt.AlignBottom
            Layout.rightMargin: 30

            AdjustTemp{
                id: adjustTempRear
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.topMargin: 50
                temp: climodel.tempRear
                onUp: {
                    climateEngine.upTempRear();
                }

                onDown:{
                    climateEngine.downTempRear();
                }
            }
            // space
            Item{
                id : space2Id
                Layout.preferredHeight:  root.spaceHeight
            }

            RowLayout{
                Layout.fillWidth: true
                Layout.alignment: Qt.AlignHCenter
                Layout.topMargin: 100
                spacing: 100
                Image{
                    id: upperId
                    width: 40
                    height: 40
                    sourceSize.width: width
                    sourceSize.height: height
                    fillMode: Image.PreserveAspectFit
                    source: mouseAreaUpper.containsPress ? "qrc:/assets/Icon/upper_white.png" : "qrc:/assets/Icon/upper_gray.png"
                    Text {
                        text: qsTr("Upper")
                        font.pixelSize: 13
                        anchors.top: upperId.bottom
                        anchors.topMargin: 2
                        font.family: "Arial"
                        font.weight: Font.ExtraBold
                        anchors.horizontalCenter: upperId.horizontalCenter
                        color : mouseAreaUpper.containsPress ? "white" : "gray"
                    }
                    MouseArea{
                        id : mouseAreaUpper
                        anchors.fill: parent
                        onPressed: {
                            timerUpper.running = true
                        }
                        onReleased: {
                            console.log("Released Upper")
                            timerUpper.running = false
                        }
                    }

                    Timer {
                        id: timerUpper
                        interval: 200
                        repeat: true
                        onTriggered: {
                            climateEngine.adjustAngleChairToUpper()
                        }
                    }
                }

                Image{
                    id: lowerId
                    width: 40
                    height: 40
                    sourceSize.width: width
                    sourceSize.height: height
                    fillMode: Image.PreserveAspectFit
                    source: mouseAreaLower.containsPress ? "qrc:/assets/Icon/Lower_white.png" : "qrc:/assets/Icon/Lower_gray.png"
                    Text {
                        text: qsTr("Lower")
                        font.pixelSize: 13
                        anchors.top: lowerId.bottom
                        anchors.topMargin: 2
                        font.family: "Arial"
                        font.weight: Font.ExtraBold
                        anchors.horizontalCenter: lowerId.horizontalCenter
                        color : mouseAreaLower.containsPress ? "white" : "gray"
                    }
                    MouseArea{
                        id : mouseAreaLower
                        anchors.fill: parent
                        onPressed:{
                            timerLower.running = true
                        }

                        onReleased: {
                            timerLower.running = false
                        }

                        Timer {
                            id: timerLower
                            interval: 200
                            repeat: true
                            onTriggered: {
                                climateEngine.adjustAngleChairToLower()
                            }
                        }
                    }
                }
                HeatSeats{
                    id: heatSeatsBehind
                    soureImage_on:"qrc:/assets/Icon/HeatSeat_Behind_white.png"
                    soureImage_off:"qrc:/assets/Icon/HeatSeat_Behind_gray.png"
                    leftRight: "right"
                    levelHeat: climodel.levelHeatSeatRear
                    onLevelChange:{
                        climateEngine.adjustHeatSeatLevelRear(heatSeatsBehind.level)
                    }
                }
            }
        }
    }
}



