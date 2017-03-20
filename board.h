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
    Q_INVOKABLE void up();
    Q_INVOKABLE void right();
    Q_INVOKABLE void down();
    Q_INVOKABLE void left();
    int get(int x, int y);
    int getdim();
    void update_tableau();

    Q_PROPERTY(QList <QString> state READ readState NOTIFY stateChanged)

    QList <QString> readState();
    //Méthodes à ajouter :
    //Stocker les derniers mouvements dans un vecteur pour pouvoir retourner


signals:

    void stateChanged();

public slots:

private :
    int** T;
    int dim;
    QList <QString> Tableau;
};

#endif // Board_H
