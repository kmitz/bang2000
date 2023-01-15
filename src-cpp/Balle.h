#ifndef BALLE_H
#define BALLE_H
#include "Const.h"
#include "Joueur.h"
#include <SDL/SDL.h>

class Balle
{
    public:

    Balle();

    int getX() {return x;}
    int getY() {return y;}
    int getOrientation() {return orientation;}
    int getDegats() {return degats;}
    void iniBalle (int orientation, int x, int y, int Vballe);
    void deplacerBalle();
    void defineImg(SDL_Surface *img);
    void setImg(SDL_Surface* img) {this->img = img;}
    SDL_Surface* getImg() {return img;}
    int getHauteur() {return img->h;}
    int getLongueur() {return img->w;}

    private:

    int x;
    int y;
    int orientation;
    int degats;
    float vx;
    float vy;
    SDL_Surface *img;
};


#endif
