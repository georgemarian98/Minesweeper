#ifndef TABLA_H
#define TABLA_H

#include"Bloc.h"
#include"Liber.h"
#include"Bomba.h"
#include<vector>

#define matrice vector< vector<Bloc*> >

class Tabla
{
private:
    matrice table;
    int     m_bombe;
    int     m_rand;
    int     m_col;
    int     m_nimerite;
    bool    m_gameOver;
public:
    Tabla(int randuri, int col, int bombe);
    ~Tabla();
    void draw(sf::RenderWindow &window);
    void revealAll();
    void floodFill(int i, int j);
    int  update(sf::RenderWindow &window, Mouse m);
    int  getBombe() { return m_bombe;}
};

#endif // TABLA_H
