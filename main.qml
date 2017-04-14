import QtQuick 2.0
import QtQuick 2.3
import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2
import QtQuick 2.5
import QtQuick.Window 2.2

ApplicationWindow {


    visible: true
    width: 480
    height: 600
    title: qsTr("2048")
    maximumHeight: 600
    maximumWidth: 480
    minimumHeight: 600
    minimumWidth: 480

    id: gamewindow

    MainForm {
        anchors.fill: parent
        mouseAreaNewGame.onClicked: vueBoard.board_init(vueBoard.get_dim());
        mouseAreaUndo.onClicked: vueBoard.go_back();

        mouseAreaOptions.onClicked: {
            var component = Qt.createComponent("page_options.qml")
            var window    = component.createObject(gamewindow)
            window.show()
        }


        //Il faut encore lie au signal cestlafin et ajouter les commandes aux buttons
        /*{
        var component = Qt.createComponent("gameover.qml")
        var window    = component.createObject(messagegameover)
        window.show()
        }*/
}
    /*Rectangle{
        id: rectangleBackground
        var component = Qt.createComponent("gameover.qml")
        if enabled {
        var window    = component.createObject(messagegameover)
        window.show()
        }*/
}




