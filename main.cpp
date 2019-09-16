#include "Minesweeper.h"

#define SIZE_PATRAT 25

int main()
{
    int rand,col,bomb;

    cout<<"Numarul de randuri: ";
    cin>>rand;
    cout<<"Numarul de coloane: ";
    cin>>col;
    cout<<"Numarul de bombe: ";
    cin>>bomb;

    system("cls");

    sf::RenderWindow window(sf::VideoMode(col * SIZE_PATRAT, rand * SIZE_PATRAT + 55), "Minesweeper");
    window.setFramerateLimit(30);

    Minesweeper joc(col,rand,bomb);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                window.close();
        }

        joc.update(window);

        window.clear();
        joc.draw(window);

        window.display();
    }
	system("pause");
    return 0;
}
