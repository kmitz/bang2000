#ifndef PARTIE_H
#define PARTIE_H

#include <string>
#include <vector>
#include <SDL/SDL.h>
#include "Const.h"
#include "Balle.h"

class Joueur;
class Obstacle;
class Bonus;


class Partie
{
    public:
    Partie();

    bool detectionCol (Joueur & joueur, Balle & balle);
    bool detectionCol (Obstacle & joueur, Balle & balle);
    bool detectionCol (Bonus & bonus, Joueur & joueur);
    void afficherScore ();
    void afficherVie ();
    void afficherNom ();
    void gestionCol (std::vector<Joueur>& vJoueurs, std::vector<Obstacle>& vObstacles, std::vector<Bonus>& vBonus);

    private:

    SDL_Surface *imgVie;
    SDL_Surface *img;


};


#endif
