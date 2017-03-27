import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2
import QtQuick 2.5
import QtQuick.Window 2.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("2048")

    MainForm {
        anchors.fill: parent
        buttonNewGame.onClicked: vueBoard.board_init();
        buttonUndo.onClicked: vueBoard.go_back();

    }
}
