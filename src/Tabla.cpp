#include "Tabla.h"
#include<stdlib.h>
#include<time.h>

#define BLOC  0
#define BOMBA 1
#define LIBER 2


Tabla::Tabla(int randuri, int col, int bombe)
{
    srand(time(NULL));

    m_rand = randuri;
    m_col = col;
    m_bombe = bombe;
    m_nimerite = bombe;
    m_gameOver = false;

    if(bombe > col * randuri){
        cout<<"Prea multe bombe!"<<endl;
        exit(1);
    }

    //creearea tablei de joc
    table.reserve(randuri);

    for(int i = 0 ; i < randuri; i++){
        vector<Bloc*> temp;
        temp.reserve(col);

        for(int j = 0; j< col; j++){
            Bloc *aux= new Bloc(25 * i + 3, 25 * j + 55);
            temp.push_back(aux);
        }

        table.push_back(temp);
    }

    //Bloc are un membru static steag, pentru cate steaguri are voie sa puna
    table[0][0]->setSteaguri(bombe);

    int nrBombe = 0;

    //punerea bombelor pe tabla
    while(nrBombe < bombe){
        int r = rand() % m_rand;
        int c = rand() % m_col;

        //daca pe pozitia generata nu ii bomba se insereaza in matrice si se actualizeaza blocurile din jur
        if(table[r][c]->instanceOf() != BOMBA){
            int x = table[r][c]->getPosition().x;
            int y = table[r][c]->getPosition().y;

            delete table[r][c];
            table[r][c] = new Bomba(x,y);

            //actualizarea blocurilor libere
            for(int i = -1; i <= 1; i++){
                for(int j = -1; j <= 1; j++){
                    int new_r = r + i;
                    int new_c = c + j;

                    //daca nu ii bloc liber sa face un bloc pentru patrat cu bombe in jur altfel se incrementeaza numarul acesteia
                    if(new_r >= 0 && new_r < m_rand && new_c >= 0 && new_c < m_col){
                        if(table[new_r][new_c]->instanceOf() == BLOC){
                            x = table[ new_r ][ new_c ]->getPosition().x;
                            y = table[ new_r ][ new_c ]->getPosition().y;

                            delete table[ new_r ][ new_c ];
                            table[ new_r ][ new_c ] = new Liber(x,y);
                        }
                        else
                            table[new_r][new_c]->adaugaBombe();
                    }
                }
            }

            nrBombe++;
        }
    }

}

Tabla::~Tabla()
{
    //eliberarea memoriei
    for(auto plansa : table)
        for(auto casuta : plansa)
            delete casuta;

    for(auto plansa : table)
        plansa.clear();
    table.clear();
}

void Tabla::draw(sf::RenderWindow &window)
{
    //afisarea  duh
    for(auto plansa : table)
        for(auto casuta : plansa)
            casuta->draw(window);
}

int Tabla::update(sf::RenderWindow &window, Mouse m)
{
    //ii gata
    if(m_gameOver)
        return 0;

    //o castigat
    if(m_nimerite == 0){
        cout<<"Bravo ai castigat!"<<endl;
        m_gameOver = true;
        revealAll();
        return 1;
    }

    for(int i = 0; i< m_rand; i++){
        for(int j =0; j < m_col; j++){
            int update =  table[i][j]->update(window,m);
            //click stanga pe un patrat
            if(update == 1){
                switch(table[i][j]->instanceOf())
                {
                case BLOC:
                    // nu ii nimic in jur, le afiseaza pe toate din jur
                    table[i][j]->setApasat(false);
                    floodFill(i,j);
                    break;

                case BOMBA:
                    //ii o bomba si o pierdut
                    cout<<"Ai pierdut!"<<endl;
                    revealAll();
                    table[i][j]->setRosu();
                    m_gameOver = true;
                    return 2;
                    break;
                }
            }
            //click dreapta
            else if(update == 2){
                //daca este pus steagul intradevar bine
                if(table[i][j]->instanceOf() == BOMBA){
                    if(table[i][j]->getSteag() == true)
                        m_nimerite--;
                    else
                        m_nimerite++;
                }
            }
        }
    }
    m_bombe = table[0][0]->getMaxSteag();

    return 0;
}

void Tabla::revealAll()
{
    for(auto plansa : table)
        for(auto casuta : plansa)

            //daca nu ii bomba
            if(!casuta->getSteag())
                casuta->setApasat(true);

            //daca o pus bomba dar nu ii acolo
            else if(casuta->instanceOf() != BOMBA){
                casuta->setApasat(true);
                casuta->setFlag(false);
            }

}

void Tabla::floodFill(int i, int j)
{
    //daca este o casuta langa o bomba sau daca patratul o fost deja afisat se opreste
    if(table[i][j]->instanceOf() == LIBER || table[i][j]->getApasat() == true || table[i][j]->getSteag() == true){
        if(table[i][j]->getSteag() == false)
            table[i][j]->setApasat(true);

        return;
    }

    table[i][j]->setApasat(true);

    for(int x = -1; x <= 1; x++){
        for(int y = -1; y <= 1; y++){
            int new_r = x + i;
            int new_c = y + j;
            if(new_r >= 0 && new_r < m_rand && new_c >= 0 && new_c < m_col)
                floodFill(new_r, new_c);
        }
    }
}
