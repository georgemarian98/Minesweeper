#ifndef UI_H
#define UI_H
#include <SFML/Graphics.hpp>
#include "Mouse.h"


class UI
{
private:
        sf::RectangleShape m_background;
        sf::CircleShape    m_fata;
        sf::RectangleShape m_blocBombe;
        sf::RectangleShape m_blocTimp;
        sf::Text           m_bomb;
        sf::Text           m_timp;
        sf::Font           m_font;
        sf::Clock          m_timpScurs;
        int                m_bombe;
        int                m_minute;
        int                m_secunde;
        bool               m_stop;
public:
        UI(int bombe, int width);
        void        draw(sf::RenderWindow & window);
        void        setStop(bool stop) { m_stop = stop;}
        void        setBomba(int bomb) { m_bombe = bomb;}
        void        setColor(sf::Color cul) { m_fata.setFillColor(cul);}
        void        reset();
        bool        update(sf::RenderWindow & window, Mouse m);
        bool        ii_pe_noi(sf::Vector2i poz);
        std::string setString(int caracter, int spatii);
};

#endif // UI_H
