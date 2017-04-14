#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <iostream>
#include <QObject>
#include <vector>
#include <QTextStream>
#include <QFile>
#include <QString>

using namespace std;

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(int l);
    ~Game();
    Q_INVOKABLE void board_init(int l); //Game
    void new_tile(int change); //Game
    Q_INVOKABLE void up(); //Game
    Q_INVOKABLE void right(); //Game
    Q_INVOKABLE void down(); //Game
    Q_INVOKABLE void left(); //Game
    void update_qtableau(int olddim = 0); //Game
    void print_Qlist(); //Game
    void add_prev_board(); //Game
    Q_INVOKABLE void go_back(); //Game
    void print_prev_size(); //Game
    Board *get_board();
    void print_board();
    string get_color(int n, int set);
    void erase_Previous();
    Q_INVOKABLE int get_dim();
    Q_INVOKABLE int get_taille();

    Q_PROPERTY(QList <QString> state READ readState NOTIFY stateChanged); //Game

    QList <QString> readState() const; //Game

    //Q_PROPERTY(bool enabled READ isEnabled NOTIFY cestlafin);

signals:

    void stateChanged();
    void cestlafin();

private:
    QList <QString> QTableau;
    vector <Board> Previous;
    int dim;
    Board* T;
    vector <string> colors1, colors2;
    int datapoints;
    bool over;
    int highscore;
    QTextStream in;
    QFile readfile;
    QString qhigh;

};

#endif // GAME_H
