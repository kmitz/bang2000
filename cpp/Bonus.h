#ifndef BONUS_H
#define BONUS_H

#include <string>
#include <vector>
#include <SDL/SDL.h>
#include "Const.h"
//#include "Balle.h"
#include <fmodex/fmod.h>
#include "Joueur.h"


class Bonus: public Joueur
{
    public:

    Bonus();

    int m_typeBonus;

    private:



};

#endif
