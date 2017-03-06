#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <board.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();

    Board B(5,8,4);
    B.init(5);
    B.set(0,0,0);
    cout << B;


    return 0;
}
