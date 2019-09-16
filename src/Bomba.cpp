#include "Bomba.h"

Bomba::Bomba(int x, int y) : Bloc(x,y)
{
    bomba.setRadius(7.5);
    bomba.setFillColor(sf::Color::Black);
    bomba.setPosition(patrat.getPosition().x + 3, patrat.getPosition().y + 3);
}

void Bomba ::draw(sf::RenderWindow& window)
{
    Bloc::draw(window);
    if(m_apasat)
        window.draw(bomba);
}

int Bomba::instanceOf()
{
    return 1;
}

