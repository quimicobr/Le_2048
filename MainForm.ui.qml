import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Layouts 1.1
import QtQuick 2.0
import QtQuick 2.3
import QtQuick.Dialogs 1.2
import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.2



Item {
    id: page
    width: 480
    height: 600

    property alias mouseAreaNewGame: mouseAreaNewGame
    property alias mouseAreaUndo: mouseAreaUndo
    property alias mouseAreaOptions: mouseAreaOptions

    Rectangle {
        id: rectangleBackground
        color: "#fdf9a7"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        border.width: 0
        anchors.fill: parent

        /*if enabled {
        var component = Qt.createComponent("Game_over.qml")
        var window    = component.createObject(messagegameover)
        window.show()
        }*/



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
                columns: vueBoard.get_dim()
                spacing: 4
                focus: true
                Keys.onPressed:  {
                  switch (event.key) {
                    case Qt.Key_Up:
                      vueBoard.up();
                      if (vueBoard.isover()==1){
                      var component = Qt.createComponent("gameover.qml")
                      var window    = component.createObject(page)
                      window.show()
                      }
                      break;
                    case Qt.Key_Down:
                      vueBoard.down();
                        if (vueBoard.isover()==1){
                        var component = Qt.createComponent("gameover.qml")
                        var window    = component.createObject(page)
                        window.show()
                        }
                      break;
                    case Qt.Key_Left:
                      vueBoard.left();
                        if (vueBoard.isover()==1){
                        var component = Qt.createComponent("gameover.qml")
                        var window    = component.createObject(page)
                        window.show()
                        }
                        break;
                    case Qt.Key_Right:
                      vueBoard.right();
                        if (vueBoard.isover()==1){
                        var component = Qt.createComponent("gameover.qml")
                        var window    = component.createObject(page)
                        window.show()
                        }
                        break;
                  }
                }
                Repeater{
                    transformOrigin: Item.Right
                    model: vueBoard.get_taille();
                    Rectangle {
                        id: rectan
                        color: "#8c8c98";
                        radius: 10;
                        width: (360-(vueBoard.get_dim()+1)*4)/vueBoard.get_dim();
                        height: (360-(vueBoard.get_dim()+1)*4)/vueBoard.get_dim();
                        Rectangle {
                            color: vueBoard.state[index+vueBoard.get_taille()];
                            radius: 10;
                            width: (360-(vueBoard.get_dim()+1)*4)/vueBoard.get_dim();
                            height: (360-(vueBoard.get_dim()+1)*4)/vueBoard.get_dim();
                            Text {
                                text: vueBoard.state[index];
                                font.bold: true;
                                verticalAlignment: Text.AlignVCenter;
                                horizontalAlignment: Text.AlignHCenter;
                                anchors.fill: parent;
                                font.pixelSize: 36*4/vueBoard.get_dim();
                                font.family: "Arial Rounded MT Bold"

                            }
                        }
                    }
                }
            }
        }

        Text {
            id: title
            x: 60
            y: 10
            width: 154
            height: 82
            color: "#020202"
            text: qsTr("2048")
            anchors.right: thedamier.left
            anchors.rightMargin: -154
            anchors.bottom: thedamier.top
            anchors.bottomMargin: 138
            styleColor: "#f8cb2c"
            //font.italic: true
            font.family: "Arial Unicode MS"
            font.wordSpacing: 0
            font.weight: Font.Normal
            style: Text.Outline
            wrapMode: Text.WrapAtWordBoundaryOrAnywhere
            font.bold: true
            fontSizeMode: Text.Fit
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHLeft
            font.pixelSize: 50
        }

        Rectangle {
            id: rectangleScore
            y: 14
            width: 81
            height: 74
            color: "#bebdbd"
            radius: 15
            anchors.left: thedamier.right
            anchors.leftMargin: -173
            anchors.bottom: thedamier.top
            anchors.bottomMargin: 142
        }

        Text {
            id: scorevalue
            x: 710
            y: 52
            width: 81
            height: 47
            color: "#ffffff"
            text: vueBoard.state[2*vueBoard.get_taille()]
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.top: rectangleScore.bottom
            anchors.topMargin: -47
            anchors.left: rectangleScore.right
            anchors.leftMargin: -81
            font.pixelSize: 16
        }

        Text {
            id: scoretext
            x: 710
            y: 30
            width: 81
            height: 16
            color: "#ffffff"
            text: qsTr("Score")
            anchors.left: rectangleScore.right
            anchors.leftMargin: -81
            anchors.top: rectangleScore.bottom
            anchors.topMargin: -67
            font.italic: false
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 14
        }

        Rectangle {
            id: rectangleHighScore
            y: 14
            width: 81
            height: 74
            color: "#bebdbd"
            radius: 15
            anchors.bottom: thedamier.top
            anchors.bottomMargin: 142
            anchors.left: thedamier.right
            anchors.leftMargin: -81
        }

        Text {
            id: highscorevalue
            x: 700
            y: 58
            width: 81
            height: 47
            color: "#ffffff"
            text: vueBoard.state[2*vueBoard.get_taille()+1]
            anchors.left: rectangleHighScore.right
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pixelSize: 16
            anchors.top: rectangleHighScore.bottom
            horizontalAlignment: Text.AlignHCenter
            anchors.topMargin: -47
            anchors.leftMargin: -81
        }

        Text {
            id: highscoretext
            width: 81
            height: 16
            color: "#ffffff"
            text: qsTr("High Score")
            anchors.left: rectangleHighScore.right
            verticalAlignment: Text.AlignVCenter
            font.bold: true
            font.pixelSize: 13
            font.italic: false
            anchors.top: rectangleHighScore.bottom
            anchors.topMargin: -67
            horizontalAlignment: Text.AlignHCenter
            anchors.leftMargin: -81
        }

        Rectangle {
            id: rectangleNewGame
            y: 103
            width: 128
            height: 48
            color: "#aba2a2"
            radius: 8
            anchors.left: thedamier.right
            anchors.leftMargin: -128
            anchors.bottom: thedamier.top
            anchors.bottomMargin: 79

            Text {
                id: textNewgame
                x: 8
                y: 8
                width: 112
                height: 32
                color: "#5f2929"
                text: qsTr("New game")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                font.pixelSize: 19
            }

            MouseArea {
                id: mouseAreaNewGame
                x: 0
                y: 0
                width: 128
                height: 48
            }
        }

        Rectangle {
            id: rectangleUndo
            x: 0
            y: 168
            width: 81
            height: 48
            color: "#aba2a2"
            radius: 8
            anchors.left: thedamier.right
            anchors.bottom: thedamier.top
            anchors.bottomMargin: 14
            anchors.leftMargin: -81

            Text {
                id: textUndo
                x: 0
                y: 0
                width: 81
                height: 48
                color: "#ffffff"
                text: qsTr("Undo")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.bold: true
                wrapMode: Text.WrapAnywhere
                font.pixelSize: 19
            }

            MouseArea {
                id: mouseAreaUndo
                x: 0
                y: 0
                width: 81
                height: 48
                hoverEnabled: false

            }
        }

        /*ToolButton {
            id: toolButton
            x: 292
            y: 175
            width: 36
            height: 36
            checked: false
            activeFocusOnPress: true
            iconSource: "Options_sign.png"
        }*/

        Rectangle {
            id: rectangleOptions
            y: 174
            width: 38
            height: 36
            color: "#00000000"
            anchors.left: thedamier.right
            anchors.leftMargin: -128
            anchors.bottom: thedamier.top
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
        }

        Text {
            id: textInstructions
            y: 114
            width: 203
            height: 27
            text: qsTr("Join the numbers and get to the 2048 tile!")
            font.bold: true
            opacity: 0.8
            renderType: Text.NativeRendering
            verticalAlignment: Text.AlignVCenter
            anchors.left: thedamier.right
            anchors.leftMargin: -360
            anchors.bottom: thedamier.top
            anchors.bottomMargin: 89
            font.pixelSize: 10
        }



    }

}
