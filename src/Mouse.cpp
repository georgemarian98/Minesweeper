#include "Mouse.h"

Mouse::Mouse()
{
    l_curent = false;
    r_curent = false;
}

bool Mouse::isPressedLeft(sf::RenderWindow& window)
{

    if(m_mouse.isButtonPressed(sf::Mouse::Left) == 0 ){
        l_curent = true;
    }
    else if(l_curent){
        l_curent = false;
        return true;
    }

    return false;
}

bool Mouse::isPressedRight(sf::RenderWindow& window)
{

    if(m_mouse.isButtonPressed(sf::Mouse::Right) == 0 ){
        r_curent = true;
    }
    else if(r_curent){
        r_curent = false;
        return true;
    }

    return false;
}

sf::Vector2i Mouse::getPositionRelativ(sf::RenderWindow& window)
{
    return m_mouse.getPosition(window);
}
