import QtQuick 2.0
import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: messagegameover
    width: 300
    height: 200
    maximumHeight: 200
    maximumWidth: 300
    minimumHeight: 200
    minimumWidth: 300

    property alias mouseAreaNewGame: mouseAreaNewGame
    property alias mouseAreaOptions: mouseAreaOptions


    Rectangle {
        id: rectanglegameover
        color: "#9691cd"
        radius: 10
        anchors.fill: parent

        Text {
            id: textgameover
            color: "#602020"
            text: qsTr("Game Over")
            anchors.left: parent.left
            anchors.leftMargin: 71
            anchors.top: parent.top
            anchors.topMargin: 35
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Rectangle {
            id: rectangleNewGame
            width: 128
            height: 48
            color: "#a2accb"
            radius: 10
            anchors.top: parent.top
            anchors.topMargin: 111
            anchors.left: parent.left
            anchors.bottomMargin: 79
            Text {
                id: textNewgame
                x: 8
                y: 8
                width: 112
                height: 32
                color: "#602020"
                text: qsTr("New game")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: mouseAreaNewGame
                x: 0
                y: 0
                width: 128
                height: 48
            }
            anchors.bottom: thedamier.top
            anchors.leftMargin: 152
        }

        Rectangle {
            id: rectangleOptions
            width: 38
            height: 36
            color: "#00000000"
            anchors.top: parent.top
            anchors.topMargin: 117
            anchors.left: parent.left
            anchors.bottomMargin: 20
            MouseArea {
                id: mouseAreaOptions
                width: 38
                height: 36
            }

            Image {
                id: image
                x: 0
                y: 0
                width: 38
                height: 36
                source: "options_icon.png"
            }
            anchors.bottom: thedamier.top
            anchors.leftMargin: 54
        }
    }

}
