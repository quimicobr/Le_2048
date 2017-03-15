#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <QObject>

using namespace std;

class Board : public QObject
{
    Q_OBJECT

public:
    explicit Board(int l, QObject *parent = 0);
    //Board(const Board &D);
    ~Board();
    friend ostream& operator<< (ostream& sortie, const Board &D);

    void init();
    void set(int x, int y, int n);
    void print();
    void board_init();
    void new_tile(int change);
    void up();
    void right();
    void down();
    void left();
    int get(int x, int y);
    int getdim();

    //Méthodes à ajouter :
    //Stocker les derniers mouvements dans un vecteur pour pouvoir retourner


signals:

public slots:

private :
    int** T;
    int dim;
};

#endif // Board_H
