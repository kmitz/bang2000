#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <vector>
#include <SDL/SDL.h>
#include "Const.h"
//#include "Balle.h"
#include <fmodex/fmod.h>
//#include <fmod.h>
class Balle;

class Joueur
{
    public:

    Joueur();

    bool estVivant();
    void setVie(int val) {vie = val;};
    int getX() {return x;}
    int getY() {return y;}
    int getVX() {return vx;}
    int getVY() {return vy;}
    void setVX(const int vx) {this->vx = vx;}
    void setVY(const int vy) {this->vy = vy;}
    int getHauteur() {return img->h;}
    int getLongueur() {return img->w;}
    int getOrientation() {return orientation;}
    int getScore () {return score;}
    int getVie() {return vie;}
    //int getNom () {return nom;}
    void deplacer(int vx, int vy);
    void etreTouche(int degats);
    void augScore (int val) {score += val;}
    void initialisationPos(int xini, int yini);
    void setNom(std::string nom) {this->nom = nom;}
    void setOrientation(int orientation) {this->orientation = orientation;}
    void setImg(SDL_Surface *imgH, SDL_Surface *imgB, SDL_Surface *imgG, SDL_Surface *imgD, SDL_Surface *imgDead);
    void useImg(int val);
    int getVballe() const {return Vballe;};
    void setVballe(int const vitesse) {Vballe = vitesse;}
    int getTballe() const {return Tballe;};
    void setTballe(int const tps) {Tballe = tps;}
    bool tirer (SDL_Surface *imgballeV, SDL_Surface *imgballeH);
    void applyBonus (int typeBonus);
    SDL_Surface* getImg(){return img;}
    bool agonie;
    //std::vector<Balle> & getBalles () {return vBalles;}
    std::vector<Balle> vBalles;

    private:

    int x;
    int y;
    int vx;
    int vy;
    int orientation;
    int vie;
    int score;
    int lastShotTime;
    int Vballe;
    int Tballe;
    SDL_Surface *imgH;
    SDL_Surface *imgB;
    SDL_Surface *imgG;
    SDL_Surface *imgD;
    SDL_Surface *imgDead;
    SDL_Surface *img;
    std::string nom;


};

#endif
