#include "board.h"

#include <iomanip>
#include <iostream>
using namespace std;

void TestValeur(int x, int y, int tx, int ty){
    if (x < 0 || y < 0){
        cout << "Indice negatif" << endl;
        throw "Indice negatif";
    }
    if (x >= tx || y >= ty){
        cout << "Indice depasse les dimensions du Board" << endl;
        throw "Indice depasse les dimensions du Board";
    }
}

void ExceptionBoard(int i, int b){
    if (i<0 || i>=b){

        string m1, m2, m3, m4;
        string file(__FILE__);
        string function(__PRETTY_FUNCTION__);

        m1 = "Borne : ";
        m2 = "Valeur rejetée : ";
        m3 = "Fichier : ";
        m4 = "Fonction : ";

        cout << m1 << b << endl;
        cout << m2 << i << endl;
        cout << m3 << file << endl;
        cout << m4 << function << endl;

        throw 1;
    }
}

Board::Board(int x, int y, int b)
{
    tx = x;
    ty = y;
    borne = b;
    T = new int* [x];
    for(int i = 0; i<x; i++){
        T[i] = new int[y];
    }
    init(0);
}

Board::Board(const Board &D){
    tx = D.tx;
    ty = D.ty;
    borne = D.borne;
    T = new int* [tx];
    for(int i = 0; i<tx; i++){
       T[i] = new int[ty];
    }

    for(int i = 0; i<tx; i++){
        for(int j = 0; j<ty; j++){
            T[i][j] = D.T[i][j];
        }
    }
}

Board::~Board(){

    if(T != NULL){
        for(int i = 0; i<tx; i++){
            delete [] T[i];
        }
        delete [] T;
        T = NULL;

    }

}


void Board::init(int n){
    ExceptionBoard(n,borne);
    for (int i = 0; i<tx; i++){
        for (int j = 0; j<ty; j++){
            T[i][j] = n;
        }
    }
}

void Board::set(int x, int y, int n){

    ExceptionBoard(n,borne);
    TestValeur(x,y,tx,ty);
    T[x][y] = n;
}

void Board::print(){
    for(int i = 0; i<tx; i++){
        for (int j = 0; j<ty; j++){
            cout << setw(6) << T[i][j];
        }
        cout << endl;
    }
}

Board& Board::operator= (const Board &D){
    if (this != &D){
        for(int i = 0; i<tx; i++){
            delete [] T[i];
        }
        delete [] T;
        tx = D.tx;
        ty = D.ty;

        T = new int* [tx];
        for(int i = 0; i<tx; i++){
            T[i] = new int[ty];
        }

        for (int i = 0; i<tx; i++){
            for (int j = 0; j<ty; j++){
                T[i][j] = D.T[i][j];
            }
        }
    }
    return *this;
}

Board operator +(const Board &D1, const Board &D2){

    Board D3(D1.tx, D1.ty, D1.borne + D2.borne);
    if (D1.tx == D2.tx && D1.ty == D2.ty){


        for(int i = 0; i<D3.tx; i++){
            for(int j = 0; j<D3.ty; j++){
                D3.T[i][j] = D1.T[i][j] + D2.T[i][j];
            }
        }
    }
    return D3;
}

Board& Board::operator +=(int a){

    for(int i = 0; i<tx; i++){
        for(int j = 0; j<ty; j++){
            T[i][j] += a;
        }
    }
    return *this;
}

ostream& operator <<(ostream&  sortie, const Board& D){
    for(int i = 0; i<D.tx; i++){
        for(int j = 0; j<D.ty; j++){
            sortie << setw(6) << D.T[i][j];
        }
        sortie << endl;
    }
    return sortie;
}
