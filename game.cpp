#include "game.h"
#include "board.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sys/time.h>


using namespace std;

Game::Game(int l)
{
    dim = l;
    T = new Board(dim);
    board_init();
    add_prev_board();

}

Game::~Game(){
    T->~Board();
}

int cherche_zero(Board *B){


    int d;
    d = B->getdim();
    for(int i = 0; i<d; i++){
        for(int j = 0; j<d; j++){
            if (B->get(i,j) == 0){
                return 1;
            }
        }
    }
    return 0;
}

int cherche_fusion_hor(Board *B){

    int d;
    d = B->getdim();
    for(int i = 0; i<d; i++){
        for(int j = 1; j<d; j++){
            if (B->get(i,j) == B->get(i,j-1)){
                return 1;
            }
        }
    }
    return 0;
}
int cherche_fusion_vert(Board *B){
    int d;
    d = B->getdim();
    for(int i = 1; i<d; i++){
        for(int j = 0; j<d; j++){
            if (B->get(i,j) == B->get(i-1,j)){
                return 1;
            }
        }
    }
    return 0;
}
void GameOver(Board *B){



    if (cherche_zero(B) == 0){
        if(cherche_fusion_hor(B) == 0){
            if(cherche_fusion_vert(B) == 0){
                throw "Game Over";

            }
        }
    }
}

void Game::board_init(){

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


    T->set(x,y,v1);
    T->set(a,b,v2);

    for (int i = 0; i<dim; i++){
        for (int j = 0; j<dim; j++)
        {
            if (T->get(i,j)){
                QTableau.append(QString::number(T->get(i,j)));
            }
            else{
                QTableau.append(QString::fromStdString(" "));
            }

        }
    }
    stateChanged();


}

void Game::new_tile(int change){
    if (change == 1){

        struct timeval tp;
        gettimeofday(&tp, NULL);
        srand(tp.tv_usec);
        vector<int> libres;
        int s, indpos, pos, auxval, val, x, y;

        for(int i = 0; i<dim; i++){
            for(int j = 0; j<dim; j++){
                if (T->get(i,j) == 0){
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
        T->set(x,y,val);
        add_prev_board();
        GameOver(T);


    }
}

void Game::right(){


    cout << "Right called" << endl;
    int lastval, lastpos, flagmerge, change = 0, aux;
    for (int i = 0; i<dim; i++){
        lastval = -1;
        lastpos = dim;
        flagmerge = 0;
        for (int j = dim-1; j>= 0; j--){
            if (T->get(i,j) != 0){
                if (T->get(i,j) != lastval || flagmerge == 1){
                    lastpos--;
                    lastval = T->get(i,j);
                    if (j != lastpos){
                        T->set(i,lastpos,T->get(i,j));
                        T->set(i,j,0);
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    aux = 2*T->get(i,lastpos);
                    T->set(i,lastpos,aux);
                    lastval = T->get(i,lastpos);
                    T->set(i,j,0);
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_qtableau();
}

void Game::left(){


    int lastval, lastpos, flagmerge, change = 0, aux;
    for (int i = 0; i<dim; i++){
        lastval = -1;
        lastpos = -1;
        flagmerge = 0;
        for (int j = 0; j<dim; j++){
            if (T->get(i,j) != 0){
                if (T->get(i,j) != lastval || flagmerge == 1){
                    lastpos ++;
                    lastval = T->get(i,j);
                    if (j != lastpos){
                        T->set(i,lastpos,T->get(i,j));
                        T->set(i,j,0);
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    aux = 2*T->get(i,lastpos);
                    T->set(i,lastpos,aux);
                    lastval = T->get(i,lastpos);
                    T->set(i,j,0);
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_qtableau();
}

void Game::up(){

    cout << "UP" << endl;

    int lastval, lastpos, flagmerge, change = 0, aux;
    for (int j = 0; j<dim; j++){
        lastval = -1;
        lastpos = -1;
        flagmerge = 0;
        for (int i = 0; i<dim; i++){
            if (T->get(i,j) != 0){
                if (T->get(i,j) != lastval || flagmerge == 1){
                    lastpos ++;
                    lastval = T->get(i,j);
                    if (i != lastpos){
                        T->set(lastpos,j,T->get(i,j));
                        T->set(i,j,0);
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    aux = 2*T->get(lastpos,j);
                    T->set(lastpos,j,aux);
                    lastval = T->get(lastpos,j);
                    T->set(i,j,0);
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_qtableau();

}

void Game::down(){


    int lastval, lastpos, flagmerge, change = 0, aux;
    for (int j = 0; j<dim; j++){
        lastval = -1;
        lastpos = dim;
        flagmerge = 0;
        for (int i = dim-1; i>= 0; i--){
            if (T->get(i,j) != 0){
                if (T->get(i,j) != lastval || flagmerge == 1){
                    lastpos--;
                    lastval = T->get(i,j);
                    if (i != lastpos){
                        T->set(lastpos,j,T->get(i,j));
                        T->set(i,j,0);
                        change = 1;
                    }
                    flagmerge = 0;
                }


                else{
                    aux = 2*T->get(lastpos,j);
                    T->set(lastpos,j,aux);
                    lastval = T->get(lastpos,j);
                    T->set(i,j,0);
                    flagmerge = 1;
                    change = 1;
                }
            }
        }
    }
    new_tile(change);
    update_qtableau();

}

QList <QString> Game::readState(){
    return QTableau;
}

void Game::update_qtableau(){

    if (QTableau.count() == dim*dim){
        for (int i = 0; i<dim*dim; i++){
            QTableau.removeFirst();
        }
    }
    else{
        throw "Erreur QT: QTableau n'a pas la bonne longueur";
    }


    for (int i = 0; i<dim; i++){
        for (int j = 0; j<dim; j++){
            QTableau.append(QString::number(T->get(i,j)));
        }
    }
    stateChanged();
}

void Game::print_Qlist(){
    if (QTableau.count() == dim*dim){
        for (int i = 0; i<dim*dim; i++){
            cout << QTableau.count() << " ";
        }
    }
    else{
        cout << "QTableau n'a pas la bonne longueur";
    }
}

void Game::add_prev_board(){
    Previous.push_back(*T);
}


void Game::go_back(){

    int taille = Previous.size();
    *T = Previous[taille - 2];
    Previous.pop_back();
    update_qtableau();

}

void Game::print_prev_size(){
    cout << "Nombre de mouvements : " << Previous.size() << endl;
}

Board* Game::get_board(){
    return T;
}

void Game::print_board(){
    T->print();
}


