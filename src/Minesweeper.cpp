#include "Minesweeper.h"

Minesweeper::Minesweeper(int x, int y, int m_bombe) : m_scor(m_bombe, x * 25 )
{
    this->m_rand = x;
    this->m_col = y;
    this->m_bombe = m_bombe;

    if(m_col < 10 || m_rand < 10){
        cout<<"Trebuie sa fie minim 10 randuri si coloane";
        exit(2);
    }

    if(m_bombe <= 0){
        cout<<"Numarul de bombe trebuie sa fie cel putin 1";
        exit(3);
    }


    m_joc = new Tabla(m_rand, m_col, m_bombe);


}

Minesweeper::~Minesweeper()
{
    delete m_joc;
}

void Minesweeper::draw(sf::RenderWindow &window)
{
    m_joc->draw(window);
    m_scor.draw(window);
}

void Minesweeper::update(sf::RenderWindow &window)
{
    int stare = m_joc->update(window,m_mouse);

    switch(stare)
    {//o castigat
    case 1:
        m_scor.setStop(true);
        m_scor.setColor(sf::Color(0,255,0));
        break;

    //o pierdut
    case 2:
        m_scor.setStop(true);
        m_scor.setColor(sf::Color(255,0,0));
        break;

    //se continua jocul
    default:
         m_scor.setBomba(m_joc->getBombe());
         if(m_scor.update(window,m_mouse)){
            // resetarea jocului
            m_scor.reset();
            delete m_joc;
            m_joc = new Tabla(m_rand,m_col,m_bombe);
            system("cls");
         }
    }


    //dunno nu merge altfel sa apesi
    m_mouse.isPressedLeft(window);
    m_mouse.isPressedRight(window);
}
