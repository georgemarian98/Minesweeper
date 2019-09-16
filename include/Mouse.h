#ifndef MOUSE_H
#define MOUSE_H
#include <SFML/Graphics.hpp>

class Mouse
{
private:
    sf::Mouse m_mouse;
    bool      l_curent;
    bool      r_curent;
public:
    Mouse();
    bool         isPressedLeft(sf::RenderWindow& window);
    bool         isPressedRight(sf::RenderWindow& window);
    sf::Vector2i getPositionRelativ(sf::RenderWindow& window);
};

#endif // MOUSE_H
