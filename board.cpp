#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sys/time.h>

using namespace std;

#include "board.h"

void TestValeur(int x, int y, int d){
    if (x < 0 || y < 0){
        throw "Indice negatif";
    }
    if (x >= d || y >= d){
        throw "Indice depasse les dimensions du Board";
    }
}



/*
void ExceptionBoard(int i){
    if (i<0){

        string m1, m2, m3, m4;
        string file(__FILE__);
        string function(__PRETTY_FUNCTION__);
        string stout;
        char si[1];
        string ssb, ssi;

        m2 = "Valeur rejetée : ";
        m3 = "Fichier : ";
        m4 = "Fonction : ";
        itoa(i,si,10);


        stout = m2 + si + "/n" + m3 + file + "/n" + m4 + function;

        throw stout;
    }
}
*/
Board::Board(int l)
{

    dim = l;
    T = new int* [dim];
    for(int i = 0; i<dim; i++){
        T[i] = new int[dim];
    }
    init();
}


Board::Board(const Board &D)
{
    dim = D.dim;
    T = new int* [dim];
    for(int i = 0; i<dim; i++){
       T[i] = new int[dim];
    }

    for(int i = 0; i<dim; i++){
        for(int j = 0; j<dim; j++){
            T[i][j] = D.T[i][j];
        }
    }
}

Board::~Board(){

    if(T != NULL){
        for(int i = 0; i<dim; i++){
            delete [] T[i];
        }
        delete [] T;
        T = NULL;

    }

}


void Board::init(){
    for (int i = 0; i<dim; i++){
        for (int j = 0; j<dim; j++){
            T[i][j] = 0;
        }
    }
}

void Board::set(int x, int y, int n){

    //ExceptionBoard(n);
    TestValeur(x,y,dim);
    T[x][y] = n;
}

ostream& operator <<(ostream&  sortie, const Board& D){
    for(int i = 0; i<D.dim; i++){
        for(int j = 0; j<D.dim; j++){
            sortie << setw(6) << D.T[i][j];
        }
        sortie << endl;
    }
    return sortie;
}

Board& Board::operator= (const Board &D){
    if (this != &D){
        for(int i = 0; i<dim; i++){
            delete [] T[i];
        }
        delete [] T;
        dim = D.dim;

        T = new int* [dim];
        for(int i = 0; i<dim; i++){
            T[i] = new int[dim];
        }

        for (int i = 0; i<dim; i++){
            for (int j = 0; j<dim; j++){
                T[i][j] = D.T[i][j];
            }
        }
    }
    return *this;
}



int Board::get(int x, int y){
    TestValeur(x,y,dim);
    return T[x][y];
}

int Board::getdim(){
    return dim;
}

void Board::print(){
    for(int i = 0; i<dim; i++){
        for(int j = 0; j<dim; j++){
            cout << setw(6) << T[i][j];
        }
        cout << endl;
    }
    cout << endl;

}

