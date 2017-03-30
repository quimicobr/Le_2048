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

    MainForm {
        anchors.fill: parent
        mouseAreaNewGame.onClicked: vueBoard.board_init();
        mouseAreaUndo.onClicked: vueBoard.go_back();
        //mouseAreaOptions.onClicked: call new window

    }

}


