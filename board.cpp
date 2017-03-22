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

int cherche_zero(Board &B){


    int d;
    d = B.getdim();
    for(int i = 0; i<d; i++){
        for(int j = 0; j<d; j++){
            if (B.get(i,j) == 0){
                return 1;
            }
        }
    }
    return 0;
}

int cherche_fusion_hor(Board &B){

    int d;
    d = B.getdim();
    for(int i = 0; i<d; i++){
        for(int j = 1; j<d; j++){
            if (B.get(i,j) == B.get(i,j-1)){
                return 1;
            }
        }
    }
    return 0;
}
int cherche_fusion_vert(Board &B){
    int d;
    d = B.getdim();
    for(int i = 1; i<d; i++){
        for(int j = 0; j<d; j++){
            if (B.get(i,j) == B.get(i-1,j)){
                return 1;
            }
        }
    }
    return 0;
}
void GameOver(Board &B){



    if (cherche_zero(B) == 0){
        if(cherche_fusion_hor(B) == 0){
            if(cherche_fusion_vert(B) == 0){
                throw "Game Over";

            }
        }
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
Board::Board(int l, QObject *parent) : QObject(parent)
{

    dim = l;
    T = new int* [dim];
    for(int i = 0; i<dim; i++){
        T[i] = new int[dim];
    }
    init();
}

/*
Board::Board(const Board &D) : QObject(D)
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
*/
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
    board_init();
    stateChanged();
    cout << "Board created"<< endl;
}

void Board::set(int x, int y, int n){

    //ExceptionBoard(n);
    TestValeur(x,y,dim);
    T[x][y] = n;
}

void Board::print(){
    for(int i = 0; i<dim; i++){
        for (int j = 0; j<dim; j++){
            cout << setw(6) << T[i][j];
        }
        cout << endl;
    }
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

void Board::board_init(){
    srand(time(NULL));
    int x, y;
    x = rand()%dim;
    y = rand()%dim;

    int a, b;
    a = rand()%dim;
    b = rand()%dim;
    while(a == x && b == y){
        a = rand()%dim;
        b = rand()%dim;
    }

    int aux1, aux2, v1, v2;
    aux1 = rand()%10;
    if (aux1 == 9){
        v1 = 4;
    }
    else{
        v1 = 2;
    }
    aux2 = rand()%10;
    if (aux2 == 9 && v1 == 2){
        v2 = 4;
    }
    else{
        v2 = 2;
    }

    set(x,y,v1);
    set(a,b,v2);

    for (int i = 0; i<dim; i++){
        for (int j = 0; j<dim; j++){
            Tableau.append(QString::number(T[i][j]));
        }
    }


}

void Board::new_tile(int change){
    if (change == 1){

    struct timeval tp;
    gettimeofday(&tp, NULL);
    srand(tp.tv_usec);
    vector<int> libres;
    int s, indpos, pos, auxval, val, x, y;

    for(int i = 0; i<dim; i++){
        for(int j = 0; j<dim; j++){
            if (T[i][j] == 0){
                libres.push_back(i*dim + j);
            }
        }
    }
    s = libres.size();
    if  (s == 0){
        throw "Couldn't put new tile";
    }
    indpos = rand()%s;
    pos = libres[indpos];
    x = pos/dim;
    y = pos%dim;

    auxval = rand()%5;
    if (auxval == 0){
        val = 4;
    }
    else{
        val = 2;
    }

    set(x,y,val);
    cout << *this << endl;

    GameOver(*this);
    }


    }

void Board::right(){


    int lastval, lastpos, flagmerge, change = 0;
    for (int i = 0; i<dim; i++){
        lastval = -1;
        lastpos = dim;
        flagmerge = 0;
        for (int j = dim-1; j>= 0; j--){
            if (T[i][j] != 0){
                if (T[i][j] != lastval || flagmerge == 1){
                    lastpos--;
                    lastval = T[i][j];
                    if (j != lastpos){
                        T[i][lastpos] = T[i][j];
                        T[i][j] = 0;
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    T[i][lastpos] = 2* T[i][lastpos];
                    lastval = T[i][lastpos];
                    T[i][j] = 0;
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_tableau();
    stateChanged();
    cout << "Right"<< endl;
}

void Board::left(){


    int lastval, lastpos, flagmerge, change = 0;
    for (int i = 0; i<dim; i++){
        lastval = -1;
        lastpos = -1;
        flagmerge = 0;
        for (int j = 0; j<dim; j++){
            if (T[i][j] != 0){
                if (T[i][j] != lastval || flagmerge == 1){
                    lastpos ++;
                    lastval = T[i][j];
                    if (j != lastpos){
                        T[i][lastpos] = T[i][j];
                        T[i][j] = 0;
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    T[i][lastpos] = 2* T[i][lastpos];
                    lastval = T[i][lastpos];
                    T[i][j] = 0;
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_tableau();
    stateChanged();
    cout << "Left" << endl;
}

void Board::up(){


    int lastval, lastpos, flagmerge, change = 0;
    for (int j = 0; j<dim; j++){
        lastval = -1;
        lastpos = -1;
        flagmerge = 0;
        for (int i = 0; i<dim; i++){
            if (T[i][j] != 0){
                if (T[i][j] != lastval || flagmerge == 1){
                    lastpos ++;
                    lastval = T[i][j];
                    if (i != lastpos){
                        T[lastpos][j] = T[i][j];
                        T[i][j] = 0;
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    T[lastpos][j] = 2* T[lastpos][j];
                    lastval = T[lastpos][j];
                    T[i][j] = 0;
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_tableau();
    stateChanged();
    cout << "Up" << endl;

}

void Board::down(){


    int lastval, lastpos, flagmerge, change = 0;
    for (int j = 0; j<dim; j++){
        lastval = -1;
        lastpos = dim;
        flagmerge = 0;
        for (int i = dim-1; i>= 0; i--){
            if (T[i][j] != 0){
                if (T[i][j] != lastval || flagmerge == 1){
                    lastpos--;
                    lastval = T[i][j];
                    if (i != lastpos){
                        T[lastpos][j] = T[i][j];
                        T[i][j] = 0;
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    T[lastpos][j] = 2* T[lastpos][j];
                    lastval = T[lastpos][j];
                    T[i][j] = 0;
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_tableau();
    stateChanged();
    cout << "Down" << endl;


}

int Board::get(int x, int y){
    TestValeur(x,y,dim);
    return T[x][y];
}

int Board::getdim(){
    return dim;
}

QList <QString> Board::readState(){
    return Tableau;
}

void Board::update_tableau(){

    if (Tableau.count() == dim*dim){
        for (int i = 0; i<dim*dim; i++){
            Tableau.removeFirst();
        }
    }
    else{
        throw "Erreur QT: Tableau n'a pas la bonne longueur";
    }


    for (int i = 0; i<dim; i++){
        for (int j = 0; j<dim; j++){
            Tableau.append(QString::number(T[i][j]));
        }
    }
}
