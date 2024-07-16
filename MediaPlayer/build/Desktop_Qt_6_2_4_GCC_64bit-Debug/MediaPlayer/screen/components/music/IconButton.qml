import QtQuick

Rectangle {
	id: rectButton
	signal clicked()
	property string src
	property bool flip
	width: 100
	height: width
	color: 'transparent'
	anchors.verticalCenter: parent.verticalCenter
	Behavior on width {
		PropertyAnimation {
			duration: 250
		}
	}
	Image {
		anchors.fill: parent;
		source: parent.src;
		fillMode: Image.PreserveAspectFit
		transform: Scale {
			xScale: flip ? -1 : 1;
			origin{
				x: flip ? width / 2 : 0
				y: flip ? height / 2 : 0
			}
		}
	}
	MouseArea {
		cursorShape: Qt.PointingHandCursor
		property int tmpWidth: 0;
		anchors.fill: parent
		Component.onCompleted: tmpWidth = rectButton.width
		onPressed: {
			if(tmpWidth == rectButton.width)
				rectButton.width += 10
		}
		onReleased: {
			rectButton.width = tmpWidth
		}
		onClicked: {
			rectButton.clicked()
		}
	}
}