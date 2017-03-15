#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ctime>
#include <sys/time.h>

#include "board.h"
#include "board2.h"

int main(int argc, char *argv[])
{
    //QGuiApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    Board B(4);
    B.init();
    cout << B << endl;

    while(1){
        try{
        B.right();
        //cout << B << endl;
        B.up();
        //cout << B << endl;
        B.left();
        //cout << B << endl;
        B.down();
        //cout << B << endl;
        }
        catch(const char* message){
            cout << message << endl;
            return 0;
        }
    }

    //return app.exec();
    return 0;
}

