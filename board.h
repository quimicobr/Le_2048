#ifndef BOARD_H
#define BOARD_H

#include <iostream>

using namespace std;


class Board
{
public:
    Board(int x, int y, int b);
    Board(const Board &D);
    ~Board();
    friend Board operator+ (const Board &D1, const Board &D2);
    Board& operator= (const Board &D);
    Board& operator+= (int a);
    friend ostream& operator<< (ostream& sortie, const Board &D);

    void init(int n);
    void set(int x, int y, int n);
    void print();



private :
    int** T;
    int tx, ty, borne;
};

#endif // Board_H
