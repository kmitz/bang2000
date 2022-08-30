

#ifdef __cplusplus
    #include <cstdlib>
#else
    #include <stdlib.h>
#endif

#include "Partie.h"
#include "Const.h"
#include "Balle.h"
#include "Controle.h"
#include <SDL/SDL.h>
#include <string>
#include <vector>
#include "Joueur.h"
#include "Obstacle.h"
#include "Bonus.h"
#include "time.h"
#include <fmodex/fmod.h>
#include <SDL_ttf/SDL_ttf.h>




using namespace std;

// variable à modifier dans settings
int NOMBRE_JOUEUR_MAX = 4;
/*int DEGATS = 20;
int VIE = 100;*/

//To do quand on est en pause les joueurs pissent

int main ( int argc, char** argv )
{



    SDL_Init(SDL_INIT_VIDEO);

    FMOD_SYSTEM *system;
    FMOD_SOUND *tir1 = NULL, *tir2 = NULL, *sound = NULL, *sonMort = NULL;
    FMOD_System_Create(&system);
    FMOD_System_Init(system, 4, FMOD_INIT_NORMAL, NULL);
    FMOD_System_CreateSound(system, "Sniper.mp3", FMOD_CREATESAMPLE, 0, &tir1);
    FMOD_System_CreateSound(system, "mp5.mp3", FMOD_CREATESAMPLE, 0, &tir2);
    FMOD_System_CreateSound(system, "scream6.mp3",  FMOD_CREATESAMPLE, 0, &sonMort);
    FMOD_System_CreateSound(system, "Round 1_ Streets of Rage Music.MP3", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &sound);


    SDL_Surface *imgJ[4] = {NULL};
    SDL_Surface *imgH1 = NULL,*imgB1 = NULL,*imgG1 = NULL,*imgD1 = NULL,*imgH2 = NULL,*imgB2 = NULL,*imgG2 = NULL,*imgD2 = NULL;
    SDL_Surface *imgH3 = NULL,*imgB3 = NULL,*imgG3 = NULL,*imgD3 = NULL,*imgH4 = NULL,*imgB4 = NULL,*imgG4 = NULL,*imgD4 = NULL;
    SDL_Surface *Jdead1 = NULL,*Jdead2 = NULL,*Jdead3 = NULL,*Jdead4 = NULL;
    SDL_Surface *obstacle_img = NULL;
    SDL_Surface *bonus_img = NULL;
    SDL_Surface *ecran = NULL, *imgballeV = NULL, *imgballeH = NULL, *Jdead = NULL;
    SDL_Rect  pos;

    //Title
    SDL_Surface *fight = NULL, *bang = NULL, *G2000 = NULL, *NewGame = NULL, *settings = NULL, *quit = NULL, *Arrow = NULL;
    SDL_Rect posFight, posBang, posG2000, posNewGame, posSettings, posQuit, posArrow, posBonustxt;

    //Settings
    SDL_Surface *menuSettings = NULL, *nbPlayers = NULL, *demandePlayers = NULL, *dmageWeapons = NULL, *demandeDmage = NULL, *lifePlayers = NULL, *demandeLife = NULL, *imputs = NULL, *quitS = NULL, *ArrowS = NULL, *barreDemande = NULL, *barreDemande2 = NULL;
    SDL_Rect posMenuSettings, posNbPlayers, posDemandePlayers, posDmageWeapons, posDemandeDmage, posLifePlayers, posDemandeLife, posImputs, posQuitS, posArrowS, posBarreDemande, posBarreDemande2;


    SDL_Event event;
    Uint8 *keystate;
    Partie partie;
    vector <Balle> vBalles;
    vector <Joueur> vJoueurs;
    vector <string> vNom;
    vector <int> vXini;
    vector <int> vYini;
    SDL_ShowCursor(false);

    TTF_Init();
    TTF_Font *policePetite = NULL;
    TTF_Font *policeGros = NULL;
    TTF_Font *policeBang = NULL;
    TTF_Font *policeG2000 = NULL;

    int previousDrawTime = 0, presentTime = 0;
    int continuer = 1, continuerSettings = 1, continuerNewGame = 1;
    int choixMenu = 0;
    int nb_tir = 0;

    srand (time(NULL));

    vNom.push_back("Bloublou");
    vNom.push_back("Bloublou2");
    vNom.push_back("Bloublou3");
    vNom.push_back("Bloublou4");
    vXini.push_back(100);
    vXini.push_back(1000);
    vXini.push_back(100);
    vXini.push_back(1000);
    vYini.push_back(100);
    vYini.push_back(LARGEUR-100);
    vYini.push_back(LARGEUR-100);
    vYini.push_back(100);

    ecran = SDL_SetVideoMode(LONGUEUR, LARGEUR, 32, SDL_SWSURFACE |SDL_FULLSCREEN | SDL_DOUBLEBUF);
    imgballeV = SDL_LoadBMP("balleV.bmp");
    imgballeH = SDL_LoadBMP("balleH.bmp");

    imgH1 = SDL_LoadBMP("Jhaut1.bmp");
    imgB1 = SDL_LoadBMP("Jbas1.bmp");
    imgG1 = SDL_LoadBMP("Jgauche1.bmp");
    imgD1 = SDL_LoadBMP("Jdroite1.bmp");

    imgH2 = SDL_LoadBMP("Jhaut2.bmp");
    imgB2 = SDL_LoadBMP("Jbas2.bmp");
    imgG2 = SDL_LoadBMP("Jgauche2.bmp");
    imgD2 = SDL_LoadBMP("Jdroite2.bmp");

    imgH3 = SDL_LoadBMP("Jhaut3.bmp");
    imgB3 = SDL_LoadBMP("Jbas3.bmp");
    imgG3 = SDL_LoadBMP("Jgauche3.bmp");
    imgD3 = SDL_LoadBMP("Jdroite3.bmp");

    imgH4 = SDL_LoadBMP("Jhaut4.bmp");
    imgB4 = SDL_LoadBMP("Jbas4.bmp");
    imgG4 = SDL_LoadBMP("Jgauche4.bmp");
    imgD4 = SDL_LoadBMP("Jdroite4.bmp");

    Arrow = SDL_LoadBMP ("fleche.bmp");
    ArrowS = SDL_LoadBMP ("fleche.bmp");
    Jdead1 = SDL_LoadBMP ("Jdead1.bmp");
    Jdead2 = SDL_LoadBMP ("Jdead2.bmp");
    Jdead3 = SDL_LoadBMP ("Jdead3.bmp");
    Jdead4 = SDL_LoadBMP ("Jdead4.bmp");

    obstacle_img = SDL_LoadBMP("bite.bmp");
    bonus_img = SDL_LoadBMP("bonus.bmp");

    barreDemande = SDL_LoadBMP ("barreDemande.bmp");
    barreDemande2 = SDL_LoadBMP ("barreDemande2.bmp");
    SDL_SetColorKey(imgH1, SDL_SRCCOLORKEY, SDL_MapRGB(imgH1->format, 0,0,0));
    SDL_SetColorKey(imgB1, SDL_SRCCOLORKEY, SDL_MapRGB(imgB1->format, 0,0,0));
    SDL_SetColorKey(imgG1, SDL_SRCCOLORKEY, SDL_MapRGB(imgG1->format, 0,0,0));
    SDL_SetColorKey(imgD1, SDL_SRCCOLORKEY, SDL_MapRGB(imgD1->format, 0,0,0));
    SDL_SetColorKey(imgH2, SDL_SRCCOLORKEY, SDL_MapRGB(imgH2->format, 0,0,0));
    SDL_SetColorKey(imgB2, SDL_SRCCOLORKEY, SDL_MapRGB(imgB2->format, 0,0,0));
    SDL_SetColorKey(imgG2, SDL_SRCCOLORKEY, SDL_MapRGB(imgG2->format, 0,0,0));
    SDL_SetColorKey(imgD2, SDL_SRCCOLORKEY, SDL_MapRGB(imgD2->format, 0,0,0));
    SDL_SetColorKey(imgH3, SDL_SRCCOLORKEY, SDL_MapRGB(imgH3->format, 0,0,0));
    SDL_SetColorKey(imgB3, SDL_SRCCOLORKEY, SDL_MapRGB(imgB3->format, 0,0,0));
    SDL_SetColorKey(imgG3, SDL_SRCCOLORKEY, SDL_MapRGB(imgG3->format, 0,0,0));
    SDL_SetColorKey(imgD3, SDL_SRCCOLORKEY, SDL_MapRGB(imgD3->format, 0,0,0));
    SDL_SetColorKey(imgH4, SDL_SRCCOLORKEY, SDL_MapRGB(imgH4->format, 0,0,0));
    SDL_SetColorKey(imgB4, SDL_SRCCOLORKEY, SDL_MapRGB(imgB4->format, 0,0,0));
    SDL_SetColorKey(imgG4, SDL_SRCCOLORKEY, SDL_MapRGB(imgG4->format, 0,0,0));
    SDL_SetColorKey(imgD4, SDL_SRCCOLORKEY, SDL_MapRGB(imgD4->format, 0,0,0));

    SDL_SetColorKey(Jdead1, SDL_SRCCOLORKEY, SDL_MapRGB(Jdead1->format, 0,0,0));
    SDL_SetColorKey(Jdead2, SDL_SRCCOLORKEY, SDL_MapRGB(Jdead2->format, 0,0,0));
    SDL_SetColorKey(Jdead3, SDL_SRCCOLORKEY, SDL_MapRGB(Jdead3->format, 0,0,0));
    SDL_SetColorKey(Jdead4, SDL_SRCCOLORKEY, SDL_MapRGB(Jdead4->format, 0,0,0));
    SDL_SetColorKey(obstacle_img, SDL_SRCCOLORKEY, SDL_MapRGB(obstacle_img->format, 0,0,0));
    SDL_SetColorKey(bonus_img, SDL_SRCCOLORKEY, SDL_MapRGB(bonus_img->format, 0,0,0));


    for (int i = 0; i < NOMBRE_JOUEUR_MAX ; i++){
        Joueur joueur;
        joueur.setNom(vNom[i]);
        joueur.setVX(VX);
        joueur.setVY(VY);
        joueur.useImg(_BAS);
        joueur.initialisationPos(vXini[i], vYini[i]);
        joueur.setOrientation(i);
        vJoueurs.push_back(joueur);
    }
    if(vJoueurs.size() >= 1) vJoueurs[0].setImg(imgH1,imgB1,imgG1,imgD1, Jdead1);
    if(vJoueurs.size() >= 2) vJoueurs[1].setImg(imgH2,imgB2,imgG2,imgD2, Jdead2);
    if(vJoueurs.size() >= 3) vJoueurs[2].setImg(imgH3,imgB3,imgG3,imgD3, Jdead3);
    if(vJoueurs.size() >= 4) vJoueurs[3].setImg(imgH4,imgB4,imgG4,imgD4, Jdead4);
    for (int i = 0; i < NOMBRE_JOUEUR_MAX ; i++){vJoueurs[i].useImg(_BAS);}

    vector<Obstacle> vObstacles;

    for (int i=0;i<_NB_OBSTACLES;i++){
        Obstacle obstacle;
        obstacle.setImg(obstacle_img,obstacle_img,obstacle_img,obstacle_img,obstacle_img);
        obstacle.useImg(_BAS);
        obstacle.setNom("bite");
        obstacle.initialisationPos(rand()%(LONGUEUR-obstacle_img->w-1)+1, rand()%(LARGEUR-obstacle_img->h-1)+1);
        obstacle.setOrientation(0);

        vObstacles.push_back(obstacle);
    }

    vector<Bonus> vBonus;

    policeGros = TTF_OpenFont("GoBoom.ttf", 95);
    policePetite = TTF_OpenFont("GoBoom.ttf", 50);
    policeBang = TTF_OpenFont("GoBoom.ttf", 200);
    policeG2000 = TTF_OpenFont("GoBoom.ttf", 175);
    SDL_Color couleurBlanche = {255, 255, 255};

    // Title Menu
    fight = TTF_RenderText_Blended(policeGros, "FIGHT!", couleurBlanche);
    bang = TTF_RenderText_Blended(policeBang, "BANG", couleurBlanche);
    G2000 = TTF_RenderText_Blended(policeG2000, "2000", couleurBlanche);
    NewGame = TTF_RenderText_Blended(policePetite, "NEW GAME", couleurBlanche);
    settings = TTF_RenderText_Blended(policePetite, "SETTINGS", couleurBlanche);
    quit = TTF_RenderText_Blended(policePetite, "QUIT", couleurBlanche);

    // Positions
    posFight.x = LONGUEUR/2 - fight->w/2;
    posFight.y = LARGEUR/2 - fight->h;
    posBang.x = LONGUEUR/2 - bang->w/2;
    posBang.y = 81;
    posG2000.x = LONGUEUR/2 - G2000->w/2;
    posG2000.y = bang->h+20;
    posNewGame.x = 250;
    posNewGame.y = posG2000.y +G2000->h+100;
    posSettings.x = 250;
    posSettings.y = posNewGame.y+NewGame->h+20;
    posQuit.x = 250;
    posQuit.y = posSettings.y+settings->h+20;
    posArrow.x = 150;
    posArrow.y = posNewGame.y + 5;

    // Settings
    menuSettings = TTF_RenderText_Blended(policeGros, "SETTINGS", couleurBlanche);
    nbPlayers = TTF_RenderText_Blended(policePetite, "NUMBER OF PLAYERS", couleurBlanche);
    //demandePlayers = TTF_RenderText_Blended(policePetite, "%d", NOMBRE_JOUEUR_MAX, couleurBlanche);
    dmageWeapons = TTF_RenderText_Blended(policePetite, "DAMAGE OF WEAPONS", couleurBlanche);
    //demandeWeapons = TTF_RenderText_Blended(policePetite, "%d", DEGATS,couleurBlanche);
    lifePlayers = TTF_RenderText_Blended(policePetite, "LIFE OF PLAYERS", couleurBlanche);
    //demandeLife = TTF_RenderText_Blended(policePetite, "%d", VIE ,couleurBlanche);
    imputs = TTF_RenderText_Blended(policePetite, "IMPUTS", couleurBlanche);
    quitS = TTF_RenderText_Blended(policePetite, "QUIT", couleurBlanche);

    // Positions
    posMenuSettings.x = LONGUEUR/2 - menuSettings->w/2;
    posMenuSettings.y = 50;
    posNbPlayers.x = 250;
    posNbPlayers.y = 200;
    posDmageWeapons.x = 250;
    posDmageWeapons.y = posNbPlayers.y + nbPlayers->h+20;
    posLifePlayers.x = 250;
    posLifePlayers.y = posDmageWeapons.y + dmageWeapons->h+20;
    posImputs.x = 250;
    posImputs.y = posLifePlayers.y + lifePlayers->h+20;
    posQuitS.x = 250;
    posQuitS.y = posImputs.y + imputs->h+20;
    posArrowS.x = 150;
    posArrowS.y = posNbPlayers.y + 5;

    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
    SDL_BlitSurface(bang, NULL, ecran, &posBang);
    SDL_BlitSurface(G2000, NULL, ecran, &posG2000);
    SDL_BlitSurface(NewGame, NULL, ecran, &posNewGame);
    SDL_BlitSurface(settings, NULL, ecran, &posSettings);
    SDL_BlitSurface(quit, NULL, ecran, &posQuit);
    SDL_BlitSurface(Arrow, NULL, ecran, &posArrow);
    SDL_Flip(ecran);
    FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sound, 0, NULL);

    while(continuer){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
            continuer = 0;
            break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym){
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_UP:
                        if(posArrow.y > posNewGame.y + 5){
                        posArrow.y = posArrow.y - 75;
                        choixMenu--;
                        if(choixMenu < 0){ choixMenu = 0;}
                        }
                        break;
                    case SDLK_DOWN:
                        if(posArrow.y < posQuit.y){
                        posArrow.y = posArrow.y + 75;
                        choixMenu++;
                        if(choixMenu > 2){ choixMenu = 2;}
                        }
                        break;
                    case SDLK_RETURN:
                        if (choixMenu == 0){

                        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                        SDL_BlitSurface(fight, NULL, ecran, &posFight);
                        SDL_Flip(ecran);
                        SDL_Delay(2000);
                        SDL_WaitEvent(&event);

                            continuerNewGame = 1;
                            while(continuerNewGame){

                                partie.gestionCol(vJoueurs, vObstacles,vBonus);

                                SDL_PollEvent(&event);
                                keystate = SDL_GetKeyState(NULL);

                                switch(event.type){
                                    case SDL_QUIT:
                                        continuerNewGame = 0;
                                        break;
                                    case SDL_KEYDOWN:
                                        if(event.key.keysym.sym == SDLK_ESCAPE) {continuerNewGame = 0;}
                                        if(event.key.keysym.sym == SDLK_F1) {
                                            for (int i=0; i < vJoueurs.size(); i++) {
                                                vJoueurs[i].setVie(VIE);
                                                vJoueurs[i].useImg(_BAS);
                                                vJoueurs[i].setVX(VX);
                                                vJoueurs[i].setVY(VY);
                                                vJoueurs[i].setVballe(VBALLE);
                                                vJoueurs[i].setTballe(TBALLE);
                                                vJoueurs[i].initialisationPos(vXini[i], vYini[i]);
                                                vJoueurs[i].setOrientation(i);
                                                vJoueurs[i].agonie = 0;
                                            }
                                            vBonus.clear();
                                            for (int i=0;i<_NB_OBSTACLES;i++){
                                                vObstacles[i].initialisationPos(rand()%(LONGUEUR-obstacle_img->w-1)+1, rand()%(LARGEUR-obstacle_img->h-1)+1);
                                            }
                                            nb_tir = 0;
                                        }
                                    break;
                                    default:
                                    break;
                                }

                                // gestion déplacements
                                controle(keystate, vJoueurs);

                                //gestion des tirs
                                //if (keystate[SDLK_KP0]) {
                                if (keystate[SDLK_RCTRL]) {
                                        if (vJoueurs.size() > 0 && vJoueurs[UN].estVivant()) {
                                            if(vJoueurs[UN].tirer(imgballeV, imgballeH)){
                                                nb_tir++;
                                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir1, 0, NULL);
                                            }
                                        }
                                }
                                if (keystate[SDLK_q]) {
                                        if (vJoueurs.size() > 1 && vJoueurs[DEUX].estVivant()) {
                                            if (vJoueurs[DEUX].tirer(imgballeV, imgballeH)){
                                                nb_tir++;
                                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir2, 0, NULL);
                                            }
                                        }
                                }
                                if (keystate[SDLK_n]) {
                                        if (vJoueurs.size() > 2  && vJoueurs[TROIS].estVivant()) {
                                            if (vJoueurs[TROIS].tirer(imgballeV, imgballeH)){
                                                nb_tir++;
                                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir1, 0, NULL);
                                            }
                                        }
                                }
                                if (keystate[SDLK_KP0]) {
                                        if (vJoueurs.size() > 3  && vJoueurs[QUATRE].estVivant()) {
                                            if (vJoueurs[QUATRE].tirer(imgballeV, imgballeH)){
                                                nb_tir++;
                                                FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, tir2, 0, NULL);
                                            }
                                        }
                                }

                                if (nb_tir>_NB_TIR_BONUS){
                                    nb_tir = 0;
                                    Bonus bonus;
                                    bonus.m_typeBonus = rand()%(_NB_TYPE_BONUS)+1;
                                    bonus.setImg(bonus_img,bonus_img,bonus_img,bonus_img,bonus_img);
                                    bonus.useImg(_BAS);
                                    bonus.initialisationPos(rand()%(LONGUEUR-bonus_img->w-1)+1, rand()%(LARGEUR-bonus_img->h-1)+1);
                                    vBonus.push_back(bonus);
                                }

                                // Effacement des balles
                                for (int i=0; i < vJoueurs.size(); i++) {
                                    for (int j=0; j < vJoueurs[i].vBalles.size(); j++) {
                                        if ((vJoueurs[i].vBalles[j].getX() > LONGUEUR) || (vJoueurs[i].vBalles[j].getY() > LARGEUR) || (vJoueurs[i].vBalles[j].getX() < 0) || (vJoueurs[i].vBalles[j].getY() < 0)) {vJoueurs[i].vBalles.erase(vJoueurs[i].vBalles.begin()+j);};
                                    }
                                }

                                for (int i = 0; i < vJoueurs.size(); i++) {
                                    if (!vJoueurs[i].estVivant() && vJoueurs[i].agonie == 0) {
                                        FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, sonMort, 0, NULL);
                                        vJoueurs[i].useImg(_DEAD);
                                        vJoueurs[i].agonie = 1;
                                    }

                                }

                                presentTime = SDL_GetTicks();
                                if ( presentTime - previousDrawTime < REFRESH_TIME) {
                                    SDL_Delay(REFRESH_TIME - presentTime + previousDrawTime);
                                }
                                previousDrawTime = SDL_GetTicks();

                                SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));

                                //Affichage Balles
                                for (int i=0; i < vJoueurs.size(); i++) {
                                    for (int j=0; j < vJoueurs[i].vBalles.size(); j++) {
                                        vJoueurs[i].vBalles[j].deplacerBalle();
                                        pos.x = vJoueurs[i].vBalles[j].getX();
                                        pos.y = vJoueurs[i].vBalles[j].getY();
                                        SDL_BlitSurface(vJoueurs[i].vBalles[j].getImg(),NULL, ecran, &pos);
                                    }
                                }

                                //Affichage joueurs
                                for (int i = 0; i < vJoueurs.size(); i++) {
                                    pos.x = vJoueurs[i].getX();
                                    pos.y = vJoueurs[i].getY();
                                    SDL_BlitSurface(vJoueurs[i].getImg(), NULL, ecran, &pos);
                                }

                                //Affichage Bonus
                                for (int i = 0; i < vBonus.size(); i++) {
                                    pos.x = vBonus[i].getX();
                                    pos.y = vBonus[i].getY();
                                    SDL_BlitSurface(vBonus[i].getImg(), NULL, ecran, &pos);
                                }

                                //Affichage obstacle
                                for (int i = 0; i < vObstacles.size(); i++) {
                                    pos.x = vObstacles[i].getX();
                                    pos.y = vObstacles[i].getY();
                                    SDL_BlitSurface(vObstacles[i].getImg(),NULL,ecran,&pos);
                                }
                                SDL_Flip(ecran);

                            }


                        }

                        //Settings
                        continuerSettings = 1;
                        if (choixMenu == 1){
                            while(continuerSettings){

                                    choixMenu = 0;
                                    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
                                    SDL_BlitSurface(menuSettings, NULL, ecran, &posMenuSettings);
                                    SDL_BlitSurface(nbPlayers, NULL, ecran, &posNbPlayers);
                                    SDL_BlitSurface(dmageWeapons, NULL, ecran, &posDmageWeapons);
                                    SDL_BlitSurface(lifePlayers, NULL, ecran, &posLifePlayers);
                                    SDL_BlitSurface(imputs, NULL, ecran, &posImputs);
                                    SDL_BlitSurface(quitS, NULL, ecran, &posQuitS);
                                    SDL_BlitSurface(ArrowS, NULL, ecran, &posArrowS);
                                    SDL_Flip(ecran);
                                    SDL_WaitEvent(&event);

                                    switch(event.type){
                                        case SDL_QUIT:
                                        continuerSettings = 0;
                                        break;
                                        case SDL_KEYDOWN:
                                            switch (event.key.keysym.sym){
                                                case SDLK_ESCAPE:
                                                    continuerSettings = 0;
                                                    break;
                                                case SDLK_UP:
                                                    if(posArrowS.y > posNbPlayers.y + 5){
                                                        posArrowS.y = posArrowS.y - 75;
                                                        choixMenu--;
                                                        if(choixMenu < 0){ choixMenu = 0;}
                                                        }
                                                    break;
                                                case SDLK_DOWN:
                                                    if(posArrowS.y < posQuitS.y - 50){
                                                        posArrowS.y = posArrowS.y + 75;
                                                        choixMenu++;
                                                    if(choixMenu > 5){ choixMenu = 5;}
                                                    }
                                                    break;
                                                case SDLK_RETURN:
                                                    if(choixMenu == 0){
                                                        continuerSettings = 1;
                                                        posBarreDemande.x = posNbPlayers.x + nbPlayers->w + 20;
                                                        posBarreDemande.y = posNbPlayers.y + 50;
                                                        posBarreDemande2.x = posNbPlayers.x + nbPlayers->w + 20;
                                                        posBarreDemande2.y = posNbPlayers.y + 50;
                                                        posDemandePlayers.x = posNbPlayers.x + nbPlayers->w + 20;
                                                        posDemandePlayers.y = posNbPlayers.y;
                                                            while(continuerSettings){
                                                                posBarreDemande.x = posNbPlayers.x + nbPlayers->w + 20;
                                                                posBarreDemande.y = posNbPlayers.y + 50;
                                                                SDL_BlitSurface(barreDemande, NULL, ecran, &posBarreDemande);
                                                                SDL_Flip(ecran);
                                                                SDL_Delay(500);
                                                                SDL_BlitSurface(barreDemande2, NULL, ecran, &posBarreDemande2);
                                                                SDL_Flip(ecran);
                                                                SDL_Delay(500);
                                                                /*scanf("%d", &NOMBRE_JOUEUR_MAX);
                                                                if (keystate[SDLK_RETURN]) {
                                                                    continuerSettings = 0;
                                                                    }*/
                                                                }
                                                    }

                                                    break;
                                                default:
                                                    break;
                                                }
                                        break;
                                        default:
                                        break;
                                    }
                            }
                        }
                        if (choixMenu == 2){
                            continuer = 0;
                        }
                    break;
                    default:
                    break;
            }
            break;
            default:
            break;
        }
        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
        SDL_BlitSurface(bang, NULL, ecran, &posBang);
        SDL_BlitSurface(G2000, NULL, ecran, &posG2000);
        SDL_BlitSurface(NewGame, NULL, ecran, &posNewGame);
        SDL_BlitSurface(settings, NULL, ecran, &posSettings);
        SDL_BlitSurface(quit, NULL, ecran, &posQuit);
        SDL_BlitSurface(Arrow, NULL, ecran, &posArrow);
        SDL_Flip(ecran);

    }





    FMOD_Sound_Release(sound);
    FMOD_Sound_Release(tir1);
    FMOD_Sound_Release(tir2);
    FMOD_System_Close(system);
    FMOD_System_Release(system);

    SDL_FreeSurface(imgJ[HAUT]);
    SDL_FreeSurface(imgJ[BAS]);
    SDL_FreeSurface(imgJ[GAUCHE]);
    SDL_FreeSurface(imgJ[DROITE]);
    SDL_FreeSurface(imgballeH);
    SDL_FreeSurface(imgballeV);
    SDL_FreeSurface(fight);
    SDL_FreeSurface(ecran);
    SDL_Quit();

    TTF_CloseFont(policePetite);
    TTF_CloseFont(policeG2000);
    TTF_CloseFont(policeBang);
    TTF_CloseFont(policeGros);
    TTF_Quit();

    printf("Exited cleanly\n");
    return 0;
}




