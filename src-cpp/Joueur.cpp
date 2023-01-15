#include "Joueur.h"
#include "Const.h"
#include "Balle.h"
#include <SDL_ttf/SDL_ttf.h>
using namespace std;

Joueur::Joueur() : vx(1), vy(1), vie(VIE), score(0), lastShotTime(0), agonie(0), Tballe(TBALLE), Vballe(VBALLE)
{
}

void Joueur::applyBonus (int typeBonus){
/*SDL_Surface *bonus_txt;
char* txt = "VITESSE!";
TTF_Font *policeTresPetite = NULL;
policeTresPetite = TTF_OpenFont("GoBoom.ttf", 20);
SDL_Color couleurBlanche = {255, 255, 255};
bonus_txt = TTF_RenderText_Blended(policeTresPetite, txt, couleurBlanche);
SDL_BlitSurface(bonus_txt, NULL, ecran, &posBonus);*/

    if (typeBonus == _VITESSE_PLUS){
        vx = vx + 2;
        vy = vy + 2;

    }
    else if (typeBonus == _VITESSE_MOINS){
        vx = vx - 1;
        vy = vy - 1;
        if (vx<1 || vy<1) {
            vx = 1;
            vy = 1;
        }
    }
    else if (typeBonus == _VIE_PLUS){
        vie += 20;
    }
    else if (typeBonus == _VIE_MOINS){
        vie -= 10;
    }
    else if (typeBonus == _VITESSE_BALLE_PLUS){
        Vballe += 5;
    }
    else if (typeBonus == _VITESSE_BALLE_MOINS){
        Vballe -= 2;
    }

}

bool Joueur::estVivant(){
    if (vie <= 0){
        return false;
    }
    else{
        return true;
    }
}

void Joueur::deplacer(int vx, int vy){
    if (x+vx > 0 && x+vx+getLongueur() < LONGUEUR) {
        x += vx;
    }
    if (y+vy > 0 && y+vy+getHauteur() < LARGEUR) {
        y += vy;
    }
}

void Joueur::etreTouche(int degats){
    vie = vie - degats;
}

void Joueur::initialisationPos(int xini, int yini){
    x = xini;
    y = yini;
}

void Joueur::setImg(SDL_Surface *imgH, SDL_Surface *imgB, SDL_Surface *imgG, SDL_Surface *imgD, SDL_Surface *imgDead){
    this->imgH = imgH;
    this->imgB = imgB;
    this->imgG = imgG;
    this->imgD = imgD;
    this->imgDead = imgDead;
}

void Joueur::useImg(int val){
    if (val == _HAUT){
        this->img = this->imgH;
    }
    else if (val == _BAS){
        this->img = this->imgB;
    }
    else if (val == _GAUCHE){
        this->img = this->imgG;
    }
    else if (val == _DROITE){
        this->img = this->imgD;
    }
    else if (val == _DEAD){
        this->img = this->imgDead;
    }
}

bool Joueur::tirer(SDL_Surface *imgballeV, SDL_Surface *imgballeH){
    int presentTime = SDL_GetTicks();

    if (presentTime - lastShotTime > Tballe) {
        Balle balle;
        balle.iniBalle(orientation, x, y, Vballe);
        if (balle.getOrientation() == HAUT || balle.getOrientation() == BAS){
            balle.setImg(imgballeV);
        }
        else if (balle.getOrientation() == DROITE || balle.getOrientation() == GAUCHE){
            balle.setImg(imgballeH);
        }
        vBalles.push_back(balle);

        lastShotTime = SDL_GetTicks();

        return true;
    }
    else return false;
}


