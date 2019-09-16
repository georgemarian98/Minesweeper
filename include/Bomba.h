#ifndef BOMBA_H
#define BOMBA_H

#include "Bloc.h"

class Bomba : public Bloc
{
private:
    sf::CircleShape bomba;
public:
    Bomba(int x, int y);
    ~Bomba() {};
    void draw(sf::RenderWindow &window);
    void adaugaBombe() {};
    int  instanceOf();
};

#endif // BOMBA_H
