#ifndef STEAG_H
#define STEAG_H

#include <SFML/Graphics.hpp>

class Steag
{
private:
    sf::CircleShape    m_steag;
    sf::RectangleShape m_stalp;
    sf::RectangleShape m_baza;
public:
    Steag(int x, int y);
    void draw(sf::RenderWindow &window);
};

#endif // STEAG_H
