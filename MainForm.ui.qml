import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
import QtQuick 2.0


Item {
    id: page
    width: 640
    height: 480

    Rectangle {
        id: rectangleBackground
        color: "#f0eb8f"
        border.width: 0
        anchors.fill: parent

        Rectangle {
            id: thedamier
            x: 124
            y: 65
            width: 360
            height: 360
            color: "#bebdbd"
            radius: 10
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            border.color: "#00000000"
            border.width: 0

            property alias grid1 : grid1
            Grid {
                id: grid1
                width: 352
                height: 352
                anchors.top: parent.top
                anchors.topMargin: 4
                anchors.left: parent.left
                anchors.leftMargin: 4
                columns: 4
                spacing: 4
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[0]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[1]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[2]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[3]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[4]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[5]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[6]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[7]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[8]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[9]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[10]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[11]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[12]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[13]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[14]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }
                Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Rectangle { color: "#8c8c98"; radius: 10; width: 85; height: 85; Text { text: vueBoard.state[15]; font.bold: true; verticalAlignment: Text.AlignVCenter; horizontalAlignment: Text.AlignHCenter; anchors.fill: parent; font.pixelSize: 24; } } }

                /*Keys.onUpPressed: vueBoard.up()

                Keys.onDownPressed: vueBoard.down()

                Keys.onLeftPressed: vueBoard.left()

                Keys.onRightPressed: vueBoard.right()*/


                  /*switch (event.key) {
                    case Qt.Key_Up:
                      vueBoard.up();
                      break;
                    case Qt.Key_Down:
                      vueBoard.down();
                      break;
                    case Qt.Key_Left:
                        vueBoard.left();
                        break;
                    case Qt.Key_Right:
                        vueBoard.right();
                        break;}}*/

            }
        }

        Text {
            id: title
            width: 154
            height: 82
            color: "#020202"
            text: qsTr("2048")
            styleColor: "#eb2802"
            font.italic: true
            font.family: "Tahoma"
            font.wordSpacing: 0
            font.weight: Font.Normal
            style: Text.Outline
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.bold: true
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 10
            font.pixelSize: 50
        }

        Button {
            id: buttonNewGame
            x: 484
            width: 148
            height: 26
            text: qsTr("New game")
            anchors.right: parent.right
            anchors.rightMargin: 10
            anchors.top: parent.top
            anchors.topMargin: 10
        }

        Text {
            id: scorevalue
            x: 710
            y: 74
            width: 81
            height: 47
            text: qsTr("Text")
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.top
            anchors.topMargin: 37
            anchors.left: parent.left
            anchors.leftMargin: 355
            font.pixelSize: 16
        }

        Text {
            id: scoretext
            width: 81
            height: 16
            text: qsTr("Score:")
            anchors.left: parent.left
            anchors.leftMargin: 355
            anchors.top: parent.top
            anchors.topMargin: 15
            font.italic: false
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 14
        }

    }

}
