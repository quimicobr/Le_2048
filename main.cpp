#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <ctime>
#include <sys/time.h>
#include <QtQml>

#include "board.h"
#include "game.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    Game G(8);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("vueBoard", &G);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));




/*
    Game G(4);
    G.print_board();
    G.right();
    G.print_board();
    G.up();
    G.print_board();
    G.left();
    G.print_board();
    G.down();
    G.print_board();
    G.go_back();
    G.print_board();
    G.go_back();
    G.print_board();
    G.right();
    G.print_board();*/



    /*while(1){
        try{
        G.right();
        cout << "Moved Right" << endl;
        //cout << B << endl;
        G.up();
        //cout << B << endl;
        G.left();
        //cout << B << endl;
        G.down();
        //cout << B << endl;
        }
        catch(const char* message){
            cout << message << endl;
            G.print_Qlist();
            //B.go_back();
            //cout << endl << B << endl;
            G.print_prev_size();
            return 0;
        }
    }
*/

    return app.exec();
    //return 0;
}
