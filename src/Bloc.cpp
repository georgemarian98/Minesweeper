#include "Bloc.h"

Bloc::Bloc(int x, int y) : m_steag(x,y)
{
    patrat.setSize(sf::Vector2f(20,20));
    patrat.setFillColor(sf::Color(160,160,160));
    patrat.setOutlineColor(sf::Color(192,192,192));
    patrat.setOutlineThickness(2);
    patrat.setPosition(sf::Vector2f(x,y));

    m_apasat = false;
    m_flag = false;
}

void Bloc::draw(sf::RenderWindow &window)
{
    window.draw(patrat);
    if(m_flag)
        m_steag.draw(window);
}

int Bloc::update(sf::RenderWindow &window,Mouse m)
{
    //click dreapta pe un patrat
    if(m.isPressedRight(window) && ii_pe_noi(m.getPositionRelativ(window)) && m_apasat == false  ){
        // daca era deja un steag pe el atunci se sterge steagul si se incrementeaza numarul de steaguri pe care le poti pune
        if(m_flag){
            m_flag = false;
            m_maxSteaguri++;
        }
        //daca nu era steag si ii bine
        else if(m_maxSteaguri){
             m_flag = true;
             m_maxSteaguri--;
        }
        return 2;
    }

    //daca este steac se iese
    if(m_flag)
        return 0;

    //click stanta pe un patrat, se afiseaza locul si se retureaza true ca o apasat
    if(m.isPressedLeft(window) && ii_pe_noi(m.getPositionRelativ(window)) ){
        patrat.setFillColor(sf::Color(192,192,192));
        m_apasat = true;
        return 1;
    }

    return 0;
}

bool Bloc::ii_pe_noi(sf::Vector2i poz)
{
    return patrat.getGlobalBounds().contains(poz.x,poz.y);
}


sf::Vector2f Bloc::getPosition()
{
    return patrat.getPosition();
}

int Bloc::instanceOf()
{
    return 0;
}

void Bloc::setApasat(bool apasat)
{
    //pentru revealAll sa se afiseze blocul
    this->m_apasat = apasat;
    patrat.setFillColor(sf::Color(192,192,192));
}

bool Bloc::getApasat()
{
    return m_apasat;
}

int Bloc::m_maxSteaguri = 0;

void Bloc::setSteaguri(int s)
{
    Bloc::m_maxSteaguri = s;
}

bool Bloc::getSteag()
{
    return m_flag;
}

void Bloc::setFlag(bool flag)
{
    m_flag = flag;
}

void Bloc::setRosu()
{
    //cand o murit sa fie mai fancy sa aiba background-ul patratului rosu, mai dramatic
    patrat.setFillColor(sf::Color::Red);
    patrat.setOutlineColor(sf::Color::Red);
}

int Bloc::getMaxSteag()
{
    return m_maxSteaguri;
}
