#ifndef CONST_H_INCLUDED
#define CONST_H_INCLUDED


/*typedef struct Joueur Joueur;
struct Joueur{
    SDL_Rect pos;
    SDL_Surface *img;

};*/

enum {UN, DEUX, TROIS, QUATRE};
enum {HAUT, BAS, GAUCHE, DROITE};
const int LARGEUR = 1024;
const int LONGUEUR = 1280;
const int TBALLE = 400;
const int VBALLE = 10;
const int VX = 3;
const int VY = 3;
const int REFRESH_TIME = 10;
const int DEGATS = 20;
const int VIE = 100;
const int _HAUT = 1;
const int _BAS = 2;
const int _GAUCHE = 3;
const int _DROITE = 4;
const int _DEAD = 5;
const int _NB_TYPE_BONUS = 8;
const int _NB_TIR_BONUS = 5;
const int _NB_OBSTACLES = 2;

const int _VITESSE_PLUS = 1;
const int _VITESSE_MOINS = 2;
const int _VIE_PLUS = 3;
const int _VIE_MOINS = 4;
const int _VITESSE_BALLE_PLUS = 5;
const int _VITESSE_BALLE_MOINS = 6;
const int _BONUS_FREEZE = 7;
const int _BONUS_BLITZ = 8;

const int _VX_BLITZ = 10;
const int _VY_BLITZ = 10;
const int _VBALLE_BLITZ = 20;
const int _TBALLE_BLITZ = 200;

const int _VX_FREEZE = 1;
const int _VY_FREEZE = 1;
const int _VBALLE_FREEZE = 2;
const int _TBALLE_FREEZE = 1000;


#endif // CONST_H_INCLUDED
