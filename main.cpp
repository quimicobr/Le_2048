#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ctime>
#include <sys/time.h>
#include <QtQml>

#include "board.h"
//#include "board2.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    Board B(4);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vueBoard", &B);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));


    //B.init();
    //cout << B << endl;

    /*//while(1){
        try{
        B.right();
        cout << B << endl;
        B.up();
        cout << B << endl;
        B.left();
        cout << B << endl;
        B.down();
        cout << B << endl;
        }
        catch(const char* message){
            cout << message << endl;
            return 0;
        }
    //}*/


    return app.exec();
}
