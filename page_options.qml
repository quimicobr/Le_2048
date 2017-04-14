import QtQuick 2.0
import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {

    id: optionspage
    width: 400
    height: 500
    maximumHeight: 500
    maximumWidth: 400
    minimumHeight: 500
    minimumWidth: 400


    Rectangle {
        id: rectanglepageoptions
        color: "#20bf0d"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Rectangle {
            id: rectangle4x41
            width: 81
            height: 48
            color: "#fdfd14"
            radius: 8
            anchors.leftMargin: 80
            anchors.top: parent.top
            anchors.topMargin: 96
            anchors.left: parent.left
            anchors.bottomMargin: 14
            Text {
                id: text4x41
                x: 0
                y: 0
                width: 81
                height: 48
                color: "#000000"
                text: qsTr("4x4")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                wrapMode: Text.WrapAnywhere
                font.bold: true
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: mouseArea4x41
                x: 0
                y: 0
                width: 81
                height: 48
                anchors.rightMargin: -21
                anchors.bottomMargin: 24
                anchors.leftMargin: 21
                anchors.topMargin: -24
                hoverEnabled: false
                onClicked: {
                    optionspage.close()
                    vueBoard.set_color(2);
                    vueBoard.board_init(4);
                }
            }
        }

        Rectangle {
            id: rectangle4x42
            x: 80
            y: 226
            width: 81
            height: 48
            color: "#fdfd14"
            radius: 8
            Text {
                id: text4x42
                x: 0
                y: 0
                width: 81
                height: 48
                color: "#000000"
                text: qsTr("5x5")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: mouseArea4x42
                x: 0
                y: 0
                width: 81
                height: 48
                hoverEnabled: false
                onClicked: {
                    optionspage.close()
                    vueBoard.set_color(2);
                    vueBoard.board_init(5);

                }
            }
        }

        Rectangle {
            id: rectangle4x43
            y: 381
            width: 81
            height: 48
            color: "#fdfd14"
            radius: 8
            anchors.left: parent.left
            anchors.bottomMargin: 96
            Text {
                id: text4x43
                x: 0
                y: 0
                width: 81
                height: 48
                color: "#000000"
                text: qsTr("6x6")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: mouseArea4x43
                x: 0
                y: 0
                width: 81
                height: 48
                hoverEnabled: false
                onClicked: {
                    optionspage.close()
                    vueBoard.set_color(2);
                    vueBoard.board_init(6);
                }
            }
            anchors.bottom: parent.bottom
            anchors.leftMargin: 80
        }

        Rectangle {
            id: rectangle4x44
            x: 406
            width: 81
            height: 48
            color: "#0334e1"
            radius: 8
            anchors.right: parent.right
            anchors.rightMargin: 80
            anchors.top: parent.top
            anchors.topMargin: 96
            anchors.bottomMargin: 14
            Text {
                id: text4x44
                x: 0
                y: 0
                width: 81
                height: 48
                color: "#ffffff"
                text: qsTr("4x4")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: mouseArea4x44
                x: 0
                y: 0
                width: 81
                height: 48
                hoverEnabled: false
                onClicked: {
                    optionspage.close()
                    vueBoard.set_color(1);
                    vueBoard.board_init(4);
                }
            }

        }

        Rectangle {
            id: rectangle4x45
            x: 239
            width: 81
            height: 48
            color: "#0334e1"
            radius: 8
            anchors.top: rectangle4x44.bottom
            anchors.topMargin: 82
            //anchors.left: thedamier.right
            Text {
                id: text4x45
                x: 0
                y: 0
                width: 81
                height: 48
                color: "#ffffff"
                text: qsTr("5x5")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: mouseArea4x45
                x: 0
                y: 0
                width: 81
                height: 48
                hoverEnabled: false
                onClicked: {
                    optionspage.close()
                    vueBoard.set_color(1);
                    vueBoard.board_init(5);
                }
            }

        }

        Rectangle {
            id: rectangle4x46
            x: 239
            y: 356
            width: 81
            height: 48
            color: "#0334e1"
            radius: 8
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 96
            anchors.right: parent.right
            anchors.rightMargin: 80
            //anchors.left: thedamier.right
            Text {
                id: text4x46
                x: 0
                y: 0
                width: 81
                height: 48
                color: "#ffffff"
                text: qsTr("6x6")
                font.pixelSize: 19
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                verticalAlignment: Text.AlignVCenter
            }

            MouseArea {
                id: mouseArea4x46
                x: 0
                y: 0
                width: 81
                height: 48
                hoverEnabled: false
                onClicked: {
                    optionspage.close()
                    vueBoard.set_color(1);
                    vueBoard.board_init(6);
                }
            }

        }
    }
}
