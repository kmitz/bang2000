
#include "Const.h"
#include "Balle.h"
#include "Controle.h"
#include "Joueur.h"
#include <SDL/SDL.h>
#include <string>
#include <vector>

using namespace std;

void controle(Uint8 *keystate, vector<Joueur> &vJoueurs){

    if(vJoueurs.size() > 0 && vJoueurs[UN].estVivant()){
        if (keystate[SDLK_UP]) {
                vJoueurs[UN].deplacer(0, -vJoueurs[UN].getVY());
                vJoueurs[UN].useImg(_HAUT);
                vJoueurs[UN].setOrientation(HAUT);
            }
        if (keystate[SDLK_DOWN]){
                vJoueurs[UN].deplacer(0, vJoueurs[UN].getVY());
                vJoueurs[UN].useImg(_BAS);
                vJoueurs[UN].setOrientation(BAS);
            }
        if (keystate[SDLK_LEFT]){
                vJoueurs[UN].deplacer(-vJoueurs[UN].getVX(), 0);
                vJoueurs[UN].useImg(_GAUCHE);
                vJoueurs[UN].setOrientation(GAUCHE);
            }
       if (keystate[SDLK_RIGHT]){
                vJoueurs[UN].deplacer(vJoueurs[UN].getVX(), 0);
                vJoueurs[UN].useImg(_DROITE);
                vJoueurs[UN].setOrientation(DROITE);
            }
}

 if (vJoueurs.size() > 1 && vJoueurs[DEUX].estVivant()){
        if (keystate[SDLK_w]) {
                vJoueurs[DEUX].deplacer(0, -vJoueurs[DEUX].getVY());
                vJoueurs[DEUX].useImg(_HAUT);
                vJoueurs[DEUX].setOrientation(HAUT);
            }
        if (keystate[SDLK_s]){
                vJoueurs[DEUX].deplacer(0, vJoueurs[DEUX].getVY());
                vJoueurs[DEUX].useImg(_BAS);
                vJoueurs[DEUX].setOrientation(BAS);
            }
        if (keystate[SDLK_a]){
                vJoueurs[DEUX].deplacer(-vJoueurs[DEUX].getVX(), 0);
                vJoueurs[DEUX].useImg(_GAUCHE);
                vJoueurs[DEUX].setOrientation(GAUCHE);
            }
       if (keystate[SDLK_d]){
                vJoueurs[DEUX].deplacer(vJoueurs[DEUX].getVX(), 0);
                vJoueurs[DEUX].useImg(_DROITE);
                vJoueurs[DEUX].setOrientation(DROITE);
            }
}

 if(vJoueurs.size() > 2 && vJoueurs[TROIS].estVivant()){
            if (keystate[SDLK_i]) {
                vJoueurs[TROIS].deplacer(0, -vJoueurs[TROIS].getVY());
                vJoueurs[TROIS].useImg(_HAUT);
                vJoueurs[TROIS].setOrientation(HAUT);
            }
        if (keystate[SDLK_k]){
                vJoueurs[TROIS].deplacer(0, vJoueurs[TROIS].getVY());
                vJoueurs[TROIS].useImg(_BAS);
                vJoueurs[TROIS].setOrientation(BAS);
            }
        if (keystate[SDLK_j]){
                vJoueurs[TROIS].deplacer(-vJoueurs[TROIS].getVX(), 0);
                vJoueurs[TROIS].useImg(_GAUCHE);
                vJoueurs[TROIS].setOrientation(GAUCHE);
            }
       if (keystate[SDLK_l]){
                vJoueurs[TROIS].deplacer(vJoueurs[TROIS].getVX(), 0);
                vJoueurs[TROIS].useImg(_DROITE);
                vJoueurs[TROIS].setOrientation(DROITE);
            }
}

 if(vJoueurs.size() > 3 && vJoueurs[QUATRE].estVivant()){
        if (keystate[SDLK_KP8]) {
                vJoueurs[QUATRE].deplacer(0, -vJoueurs[QUATRE].getVY());
                vJoueurs[QUATRE].useImg(_HAUT);
                vJoueurs[QUATRE].setOrientation(HAUT);
            }
        if (keystate[SDLK_KP5]){
                vJoueurs[QUATRE].deplacer(0, vJoueurs[QUATRE].getVY());
                vJoueurs[QUATRE].useImg(_BAS);
                vJoueurs[QUATRE].setOrientation(BAS);
            }
        if (keystate[SDLK_KP4]){
                vJoueurs[QUATRE].deplacer(-vJoueurs[QUATRE].getVX(), 0);
                vJoueurs[QUATRE].useImg(_GAUCHE);
                vJoueurs[QUATRE].setOrientation(GAUCHE);
            }
       if (keystate[SDLK_KP6]){
                vJoueurs[QUATRE].deplacer( vJoueurs[QUATRE].getVX(), 0);
                vJoueurs[QUATRE].useImg(_DROITE);
                vJoueurs[QUATRE].setOrientation(DROITE);
            }


}

}

