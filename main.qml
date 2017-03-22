import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("2048")

    MainForm {
        anchors.fill: parent

    }

    Grid {

          Keys.onUpPressed: cout << "UP" << endl;

          Keys.onDownPressed: vueBoard.down()

          Keys.onLeftPressed: vueBoard.left()

          Keys.onRightPressed: vueBoard.right()

    }

}
