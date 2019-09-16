#include "Liber.h"

sf::Font Liber::m_font;
sf::Vector3i* Liber::m_numere ;


Liber::Liber(int x, int y) : Bloc(x,y)
{
    m_numere = new sf::Vector3i[8];
    m_numere[0] = sf::Vector3i(0,0,255);
    m_numere[1] = sf::Vector3i(51,102,0);
    m_numere[2] = sf::Vector3i(255,0,0);
    m_numere[3] = sf::Vector3i(0,0,102);
    m_numere[4] = sf::Vector3i(204,102,0);
    m_numere[5] = sf::Vector3i(0,102,102);
    m_numere[6] = sf::Vector3i(0,0,0);
    m_numere[7] = sf::Vector3i(96,96,96);

    m_nrBombe = 1;

    if (!m_font.loadFromFile("resources/fontNumere.otf"))
        exit(1);

    m_text.setFont(m_font);
    m_text.setCharacterSize(24);
    m_text.setPosition(patrat.getPosition().x + 2, patrat.getPosition().y  - 4);

    string a;
    a.push_back(m_nrBombe + 48);
    m_text.setString(a);
    m_text.setColor(sf::Color(m_numere[m_nrBombe -1].x,m_numere[m_nrBombe - 1].y,m_numere[m_nrBombe - 1].z));
}

Liber::~Liber()
{
    delete m_numere;
}

void Liber::draw(sf::RenderWindow &window)
{
    Bloc::draw(window);

    if(m_apasat)
        window.draw(m_text);
}

void Liber::adaugaBombe()
{
    this->m_nrBombe++;
    string a;
    a.push_back(m_nrBombe + 48);
    m_text.setString(a);
    m_text.setColor(sf::Color(m_numere[m_nrBombe -1].x, m_numere[m_nrBombe - 1].y, m_numere[m_nrBombe - 1].z));
}

int Liber::instanceOf()
{
    return 2;
}
