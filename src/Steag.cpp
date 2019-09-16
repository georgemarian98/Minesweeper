#include "Steag.h"

Steag::Steag(int x, int y) : m_steag(6.f,3)
{
    m_steag.setFillColor(sf::Color::Red);
    m_steag.setPosition(x + 5,y );
    m_steag.rotate(30);

    m_stalp.setFillColor(sf::Color::Black);
    m_stalp.rotate(90);
    m_stalp.setPosition(x + 12,y + 3);
    m_stalp.setSize(sf::Vector2f(15,2));

    m_baza.setFillColor(sf::Color::Black);
    m_baza.setPosition(x + 5,y + 17);
    m_baza.setSize(sf::Vector2f(12,2));
}

void Steag::draw(sf::RenderWindow &window){
    window.draw(m_stalp);
    window.draw(m_steag);
    window.draw(m_baza);

}
