#include "UI.h"

#include <iostream>
#include<string.h>


UI::UI(int bombe, int width)
{
    m_bombe = bombe;
    m_stop = false;

    m_background.setSize(sf::Vector2f(width - 4,46));
    m_background.setFillColor(sf::Color(128,128,128));
    m_background.setOutlineColor(sf::Color::White);
    m_background.setOutlineThickness(2);
    m_background.setPosition(1,4);

    m_blocBombe.setSize(sf::Vector2f(55,35));
    m_blocBombe.setFillColor(sf::Color::Black);
    m_blocBombe.setPosition(5,10);

    m_blocTimp.setSize(sf::Vector2f(80,35));
    m_blocTimp.setFillColor(sf::Color::Black);
    m_blocTimp.setPosition(width - 85,10);

    m_fata.setRadius(15);
    m_fata.setFillColor(sf::Color::Yellow);
    m_fata.setPosition(width / 2 - 20,13);

    m_minute  = 0;
    m_secunde = 0;

    if (!m_font.loadFromFile("resources/digital.ttf"))
        exit(1);


    m_bomb.setString( setString(m_bombe,3) );
    m_bomb.setCharacterSize(38);
    m_bomb.setFont(m_font);
    m_bomb.setColor(sf::Color::Red);
    m_bomb.setPosition(5,5);

    std::string a;
    a += setString(m_minute,2);
    a += ":";
    a += setString(m_secunde,2);
    m_timp.setString(a);
    m_timp.setCharacterSize(38);
    m_timp.setFont(m_font);
    m_timp.setColor(sf::Color::Red);
    m_timp.setPosition(m_blocTimp.getPosition().x ,5);
}

void UI::draw(sf::RenderWindow& window)
{
    window.draw(m_background);
    window.draw(m_blocBombe);
    window.draw(m_blocTimp);
    window.draw(m_fata);
    window.draw(m_bomb);
    window.draw(m_timp);

}

bool UI::update(sf::RenderWindow & window, Mouse m)
{
    if(m.isPressedLeft(window) && ii_pe_noi(m.getPositionRelativ(window)))
        return true;

    if(m_stop)
        return false;

    m_secunde = m_timpScurs.getElapsedTime().asSeconds();
    if(m_secunde == 60){
        m_minute++;
        m_secunde = 0;
        m_timpScurs.restart();
    }

    std::string a;
    a += setString(m_minute,2);
    a += ":";
    a += setString(m_secunde,2);
    m_timp.setString(a);

    m_bomb.setString( setString(m_bombe,3) );

    return false;
}

std::string UI::setString(int caracter,int spatii)
{
    std::string a;
    int cifre = 0;
    while(cifre < spatii){
        a.push_back(caracter % 10 + 48);
        caracter /= 10;
        cifre++;
    }

    reverse(a.begin(), a.end());
    return a;

}

bool UI::ii_pe_noi(sf::Vector2i poz)
{
    return m_fata.getGlobalBounds().contains(poz.x, poz.y);
}

void UI::reset()
{
    m_minute = 0;
    m_secunde = 0;
    m_stop = false;
    m_timpScurs.restart();
    m_fata.setFillColor(sf::Color::Yellow);
}
