import QtQuick
import QtQuick.Layouts

ColumnLayout{
    id : heatingSeats
    //
    signal levelChange(var levelHeat)
    property int level: 0
    property string soureImage_on: ""
    property string soureImage_off:""
    property string leftRight: "left"
    property int levelHeat: 0
    Layout.preferredWidth: headtedSeatsImage.implicitWidth
    //
    Image{
        id: headtedSeatsImage
        width: 50
        height: 50
        sourceSize.width: width
        sourceSize.height: height
        Layout.alignment: Qt.AlignHCenter
        fillMode: Image.PreserveAspectFit
        source: (heatingSeats.level !== 0) ? heatingSeats.soureImage_on : heatingSeats.soureImage_off
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(heatingSeats.level >= 0 && heatingSeats.level < 3)
                {
                    heatingSeats.level++;
                }
                else if(heatingSeats.level === 3)
                {
                    heatingSeats.level = 0
                }
                heatingSeats.levelChange(heatingSeats.level)
            }
        }
    }

    //
    Row{
        id: rowLevelHeatSeat
        Layout.alignment: Qt.AlignHCenter
        Layout.leftMargin: (heatingSeats.leftRight === "left") ? 10 : 0
        Layout.rightMargin: (heatingSeats.leftRight === "right") ? 8 : 0

        spacing: 5
        Rectangle{
            width: 10
            height: 5
            color: heatingSeats.levelHeat >= 1 ? "#AB5153" : "gray" //heatingSeats.level >= 1 ? "#AB5153" : "gray"
        }
        Rectangle{
            width: 10
            height: 5
            color: heatingSeats.levelHeat >= 2 ? "#AB5153" : "gray"
        }
        Rectangle{
            width: 10
            height: 5
            color: heatingSeats.levelHeat >= 3 ? "#AB5153" : "gray"
        }
    }
}
