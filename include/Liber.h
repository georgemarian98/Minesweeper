#ifndef LIBER_H
#define LIBER_H

#include <Bloc.h>

class Liber : public Bloc
{
private:
    sf::Text             m_text;
    static sf::Vector3i *m_numere;
    static sf::Font      m_font;
    int                  m_nrBombe;
public:
    Liber(int x, int y);
    ~Liber();
    void draw(sf::RenderWindow &window);
    void adaugaBombe();
    int  instanceOf();
};

#endif // LIBER_H
