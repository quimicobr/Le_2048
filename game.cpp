#include "game.h"
#include "board.h"
#include <iomanip>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <sys/time.h>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

Game::Game(int l)
{
    dim = l;
    T = new Board(dim);
    colors.push_back("#008c8c98");
    /*colors.push_back("#fef4f4");
    colors.push_back("#beac88");
    colors.push_back("#f8b650");
    colors.push_back("#f1b7b3");
    colors.push_back("#f15252");
    colors.push_back("#f7c81f");
    colors.push_back("#f7f41f");
    colors.push_back("#98891a");
    colors.push_back("#fb5b6b");
    colors.push_back("#c3c35b");
    colors.push_back("#fcfc07");
    colors.push_back("#7f7c25");*/

    colors.push_back("#739EAC");//2
    colors.push_back("#55766F");//4
    colors.push_back("#B99F79");//8
    colors.push_back("#FBA950");//16
    colors.push_back("#F68E25");//32
    colors.push_back("#D55F19");//64

    colors.push_back("#A72404");//128

    colors.push_back("#D54500");//256

    colors.push_back("#FFB31F");//512
    colors.push_back("#FFDA1F");//1024
    colors.push_back("#FCFF1F");//2048

    colors.push_back("#C7EDE4");//4096
    colors.push_back("#009DDC");//8192


    for (int i = 0; i<dim*dim; i++){
        QTableau.append(QString::fromStdString(" "));
        QTableau.append(QString::fromStdString(" "));
    }

    QTableau.append(QString::number(0));

    board_init();




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

    T->init();

    erase_Previous();
    struct timeval tp;
    gettimeofday(&tp, NULL);
    srand(tp.tv_usec);
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
    update_qtableau();
    add_prev_board();

    datapoints = thehighscore();

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

    int lastval, lastpos, flagmerge, change = 0, aux, var_points = 0;
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
                    var_points = var_points + aux;
                }
            }
        }
    }
    T->add_points(var_points);
    try{
    new_tile(change);
    }
    catch(const char* message){
        cout << message << endl;
        board_init();
    }

    gamepoints = var_points;
    update_qtableau();

}

void Game::left(){


    int lastval, lastpos, flagmerge, change = 0, aux, var_points = 0;
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
                    var_points = var_points + aux;
                }
            }
        }
    }
    T->add_points(var_points);
    try{
    new_tile(change);
    }
    catch(const char* message){
        cout << message << endl;
        board_init();
    }

    gamepoints = var_points;
    update_qtableau();


}

void Game::up(){


    int lastval, lastpos, flagmerge, change = 0, aux, var_points = 0;
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
                    var_points = var_points + aux;
                }
            }
        }
    }
    T->add_points(var_points);
    try{
    new_tile(change);
    }
    catch(const char* message){
        cout << message << endl;
        board_init();
    }

    gamepoints = var_points;
    update_qtableau();





}

void Game::down(){

    int lastval, lastpos, flagmerge, change = 0, aux, var_points = 0;
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
                    var_points = var_points + aux;
                }
            }
        }
    }
    T->add_points(var_points);
    try{
    new_tile(change);
    }
    catch(const char* message){
        cout << message << endl;
        board_init();
    }

    gamepoints = var_points;
    update_qtableau();




}

QList <QString> Game::readState() const{
    return QTableau;
}

void Game::update_qtableau(){

    if (QTableau.count() == 2*dim*dim + 1){
        for (int i = 0; i<dim*dim; i++){
            QTableau.removeFirst();
            QTableau.removeFirst();
        }
        QTableau.removeFirst();
        for (int i = 0; i<dim; i++){
            for (int j = 0; j<dim; j++){
                if (T->get(i,j)){
                    QTableau.append(QString::number(T->get(i,j)));

                }
                else{
                    QTableau.append(QString::fromStdString(" "));
                }
            }
        }
        for (int i = 0; i<dim; i++){
            for (int j = 0; j<dim; j++){
                QTableau.append(QString::fromStdString(get_color(T->get(i,j))));
            }
        }

        QTableau.append(QString::number(T->get_points()));
    }
    else{
        throw "Erreur QT: QTableau n'a pas la bonne longueur";
    }

    //cout<<"cheguei"<<endl;
    //newhighscore();



    stateChanged();
}

void Game::print_Qlist(){
    if (QTableau.count() == 2*dim*dim + 1){
        for (int i = 0; i<(2*dim*dim + 1); i++){
            cout << QTableau[i].toStdString() << " ";
        }
        cout << endl;
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
    if (taille > 1){
        *T = Previous[taille - 2];
        Previous.pop_back();
        update_qtableau();
    }

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

string Game::get_color(int n){

    if (n != 0){
        int valmax, ind;
        valmax = colors.size() - 1;
        double ndouble = double(n);
        double inddouble;
        inddouble = log2(ndouble);
        ind = int(inddouble + 0.5);
        if (ind <= valmax){
            return colors[ind];
        }
        else{
            return colors[valmax];
        }
    }
    else{
        return colors[0];
    }


}

void Game::erase_Previous(){
    int s;
    s = Previous.size();
    for (int i = 0; i<s; i++){
        Previous.pop_back();
    }
}

void Game::newhighscore(){
    if (gamepoints>datapoints){
        QTableau.append(QString::number(gamepoints));
        stringstream ss;
        ss << gamepoints;
        string myString = ss.str();
        fstream myfile;
        myfile.open("highscoredata.txt",fstream::out | fstream::trunc);
        myfile << "" << myString;
        myfile.close();
    }
    else
        QTableau.append(QString::number(datapoints));

}

int Game::thehighscore(){
    char ths;
    int iths;
    fstream myfile;
    myfile.open("highscoredata.txt", fstream::in);
    myfile >> ths;
    stringstream(ths) >> iths;
    cout<<""<<iths<<endl;
    myfile.close();
    return iths;
}
