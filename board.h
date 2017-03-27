#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;

class Board
{

public:
    //Creer classe board e classe game

    Board(int l); //Board
    Board(const Board &D); //Board
    ~Board(); //Board
    friend ostream& operator<< (ostream& sortie, const Board &D); //Board
    Board& operator= (const Board &D);

    void init(); //Board
    void set(int x, int y, int n); //Board
    void print();

    int get(int x, int y); //Board
    int getdim(); //Board


private :
    int** T;
    int dim;
};

#endif // Board_H
