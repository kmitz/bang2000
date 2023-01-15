#include "Balle.h"

using namespace std;

Balle::Balle() : vx(0), vy(0), degats(DEGATS)
{
}

void Balle::deplacerBalle()
{
    x += vx;
    y += vy;

}

void Balle::iniBalle (int orientation, int x, int y, int Vballe)
{
    this->orientation = orientation;

    if(orientation == HAUT){
        this->x = x + 30;
        this->y = y;
        vy = -Vballe;
        vx = 0;
    }

    else if(orientation == BAS){
        this->x = x + 12;
        this->y = y + 60;
        vy = Vballe;
        vx = 0;
    }

    else if(orientation == DROITE){
        this->x = x + 54;
        this->y = y + 28;
        vy = 0;
        vx = Vballe;
    }

    else if(orientation == GAUCHE){
        this->x = x;
        this->y = y + 28;
        vy = 0;
        vx = -Vballe;
    }
}
