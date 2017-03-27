#ifndef GAME_H
#define GAME_H

#include "board.h"
#include <iostream>
#include <QObject>
#include <vector>

using namespace std;

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(int l);
    ~Game();
    void board_init(); //Game
    void new_tile(int change); //Game
    Q_INVOKABLE void up(); //Game
    Q_INVOKABLE void right(); //Game
    Q_INVOKABLE void down(); //Game
    Q_INVOKABLE void left(); //Game
    void update_qtableau(); //Game
    void print_Qlist(); //Game
    void add_prev_board(); //Game
    void go_back(); //Game
    void print_prev_size(); //Game
    Board *get_board();
    void print_board();

    Q_PROPERTY(QList <QString> state READ readState NOTIFY stateChanged); //Game

    QList <QString> readState(); //Game

    //Méthodes à ajouter :
    //Stocker les derniers mouvements dans un vecteur pour pouvoir retourner

signals:

    void stateChanged();

private:
    QList <QString> QTableau;
    vector <Board> Previous;
    int dim;
    Board* T;
};

#endif // GAME_H
