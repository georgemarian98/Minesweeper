#ifndef BLOC_H
#define BLOC_H

#include<iostream>
#include "Steag.h"
#include "Mouse.h"
using namespace std;

class Bloc
{
private:
    static int         m_maxSteaguri;
    bool               m_flag;
    Steag              m_steag;
protected:
    sf::RectangleShape patrat;
    bool               m_apasat;
public:
    Bloc(int x, int y);
    virtual ~Bloc() {};
    virtual void draw(sf::RenderWindow &window);
    virtual int  update(sf::RenderWindow &window,Mouse m);
    virtual int  instanceOf();
    virtual void adaugaBombe() {};
    void         setApasat(bool apasat);
    void         setSteaguri(int s);
    void         setFlag(bool flag);
    void         setRosu();
    bool         ii_pe_noi(sf::Vector2i poz);
    bool         getApasat();
    bool         getSteag();
    int          getMaxSteag();
    sf::Vector2f getPosition();
};


#endif // BLOC_H
