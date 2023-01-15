#include "Partie.h"
#include "Const.h"
#include "Balle.h"
#include "Controle.h"
#include "Joueur.h"
#include "Obstacle.h"
#include "Bonus.h"
#include <SDL/SDL.h>
#include <string>
#include <vector>

using namespace std;

Partie::Partie(){}

void Partie::gestionCol (vector<Joueur>& vJoueurs, vector<Obstacle>& vObstacles, vector<Bonus>& vBonus){
int typeBonus = 0;
SDL_Rect posBonustxt;
    for (int i = 0; i < vJoueurs.size(); i++){
        for (int j = 0; j < vJoueurs[i].vBalles.size(); j++){
            for (int k = 0; k < vJoueurs.size(); k++){
                if (k!=i) {
                   if (detectionCol(vJoueurs[k], vJoueurs[i].vBalles[j]) == true) {
                        vJoueurs[i].vBalles.erase(vJoueurs[i].vBalles.begin()+j);
                        vJoueurs[k].etreTouche(vJoueurs[i].vBalles[j].getDegats());
                        vJoueurs[i].augScore(vJoueurs[i].vBalles[j].getDegats());
                   }
                }
            }
        }
    }

    for (int i = 0; i < vJoueurs.size(); i++){
        for (int j = 0; j < vJoueurs[i].vBalles.size(); j++){
                for (int k = 0; k < vObstacles.size(); k++){
                   if (detectionCol(vObstacles[k], vJoueurs[i].vBalles[j]) == true) {
                        vJoueurs[i].vBalles.erase(vJoueurs[i].vBalles.begin()+j);
                   }
                }
        }
    }

    for (int i = 0; i < vJoueurs.size(); i++){
            for (int j = 0; j < vBonus.size(); j++){
                   if (detectionCol(vBonus[j], vJoueurs[i]) == true) {
                        typeBonus = vBonus[j].m_typeBonus;
                        //posBonustxt.x = vBonus[j].x;
                        //posBonustxt.y = vBonus[j].y;
                        if (typeBonus == _BONUS_BLITZ){
                            for (int l = 0; i < vJoueurs.size(); i++){
                                vJoueurs[l].setVX(_VX_BLITZ);
                                vJoueurs[l].setVX(_VY_BLITZ);
                                vJoueurs[l].setVballe(_VBALLE_BLITZ);
                                vJoueurs[l].setTballe(_TBALLE_BLITZ);
                            }
                        }
                        else if (typeBonus == _BONUS_FREEZE){
                            for (int l = 0; i < vJoueurs.size(); i++){
                                vJoueurs[l].setVX(_VX_FREEZE);
                                vJoueurs[l].setVX(_VX_FREEZE);
                                vJoueurs[l].setVballe(_VBALLE_FREEZE);
                                vJoueurs[l].setTballe(_TBALLE_FREEZE);
                            }
                        }
                        else {
                            vJoueurs[i].applyBonus(typeBonus);
                        }
                        vBonus.erase(vBonus.begin()+j);
                   }
            }
    }

}

bool Partie::detectionCol (Obstacle & joueur, Balle & balle){

    int hautBalle, hautJoueur;
    int droiteBalle, droiteJoueur;
    int basBalle, basJoueur;
    int gaucheBalle, gaucheJoueur;

    hautBalle = balle.getY();
    gaucheBalle = balle.getX();
    basBalle = balle.getY() + balle.getHauteur();
    droiteBalle = balle.getX() + balle.getLongueur();

    hautJoueur = joueur.getY();
    gaucheJoueur = joueur.getX();
    basJoueur = joueur.getY() + joueur.getHauteur();
    droiteJoueur = joueur.getX() + joueur.getLongueur();

    if (droiteBalle < gaucheJoueur){return false;}
    if (hautBalle > basJoueur){return false;}
    if (basBalle < hautJoueur){return false;}
    if (gaucheBalle > droiteJoueur){return false;}
    else {return true;}

}

bool Partie::detectionCol (Joueur & joueur, Balle & balle){

    int hautBalle, hautJoueur;
    int droiteBalle, droiteJoueur;
    int basBalle, basJoueur;
    int gaucheBalle, gaucheJoueur;

    hautBalle = balle.getY();
    gaucheBalle = balle.getX();
    basBalle = balle.getY() + balle.getHauteur();
    droiteBalle = balle.getX() + balle.getLongueur();

    hautJoueur = joueur.getY();
    gaucheJoueur = joueur.getX();
    basJoueur = joueur.getY() + joueur.getHauteur();
    droiteJoueur = joueur.getX() + joueur.getLongueur();

    if (droiteBalle < gaucheJoueur){return false;}
    if (hautBalle > basJoueur){return false;}
    if (basBalle < hautJoueur){return false;}
    if (gaucheBalle > droiteJoueur){return false;}
    else {return true;}

}

bool Partie::detectionCol (Bonus & bonus, Joueur & joueur){

    int hautBalle, hautJoueur;
    int droiteBalle, droiteJoueur;
    int basBalle, basJoueur;
    int gaucheBalle, gaucheJoueur;

    hautBalle = joueur.getY();
    gaucheBalle = joueur.getX();
    basBalle = joueur.getY() + joueur.getHauteur();
    droiteBalle = joueur.getX() + joueur.getLongueur();

    hautJoueur = bonus.getY();
    gaucheJoueur = bonus.getX();
    basJoueur = bonus.getY() + bonus.getHauteur();
    droiteJoueur = bonus.getX() + bonus.getLongueur();

    if (droiteBalle < gaucheJoueur){return false;}
    if (hautBalle > basJoueur){return false;}
    if (basBalle < hautJoueur){return false;}
    if (gaucheBalle > droiteJoueur){return false;}
    else {return true;}

}

