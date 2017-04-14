import QtQuick 2.0
import QtQuick 2.3
import QtQuick.Controls 1.2
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2
import QtQuick 2.5
import QtQuick.Window 2.2

ApplicationWindow {
    visible: true
    id: messagegameover
    width: 300
    height: 200
    maximumHeight: 200
    maximumWidth: 300
    minimumHeight: 200
    minimumWidth: 300
    flags: Qt.FramelessWindowHint


    Rectangle {
        id: rectanglegameover
        color: "#9691cd"
        radius: 0
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
            id: rectangleNewGame2
            width: 128
            height: 48
            color: "#a2accb"
            radius: 10
            anchors.leftMargin: 142
            anchors.top: parent.top
            anchors.topMargin: 111
            anchors.left: parent.left
            anchors.bottomMargin: 79
            Text {
                id: textNewgame2
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
                id: mouseAreaNewGame2
                x: 0
                y: 0
                width: 128
                height: 48
                onClicked: {
                        vueBoard.board_init(vueBoard.get_dim());
                        messagegameover.close()
                }
            }

        }

        Rectangle {
            id: rectangleOptions2
            width: 38
            height: 36
            color: "#00000000"
            anchors.leftMargin: 52
            anchors.top: parent.top
            anchors.topMargin: 117
            anchors.left: parent.left
            anchors.bottomMargin: 20

            MouseArea {
                id: mouseAreaOptions2
                width: 38
                height: 36
                onClicked: {
                        var component = Qt.createComponent("page_options.qml")
                        var window    = component.createObject(page)
                        window.show()
                        messagegameover.close()
                }
            }

            Image {
                id: image2
                x: 0
                y: 0
                width: 38
                height: 36
                source: "options_icon.png"
            }

        }
    }

}
