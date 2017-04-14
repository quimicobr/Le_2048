import QtQuick 2.0
import QtQuick 2.3
import QtQuick.Controls 1.2

ApplicationWindow {
    id: messagegameover
    visible: true
    width: 300
    height: 200
    maximumHeight: 200
    maximumWidth: 300
    minimumHeight: 200
    minimumWidth: 300

    Game_overForm {

        anchors.fill: parent
        mouseAreaNewGame.onClicked: vueBoard.board_init(vueBoard.get_dim());
        mouseAreaOptions.onClicked: {
            var component = Qt.createComponent("page_options.qml")
            var window    = component.createObject(messagegameover)
            window.show()
        }



}
}
