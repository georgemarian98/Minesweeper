#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "Tabla.h"
#include "UI.h"


class Minesweeper
{
private:
    Tabla* m_joc;
    UI     m_scor;
    Mouse  m_mouse;
    int    m_col;
    int    m_rand;
    int    m_bombe;
public:
    Minesweeper(int x, int y, int m_bombe);
    ~Minesweeper();
    void draw(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
};

#endif // MINESWEEPER_H
