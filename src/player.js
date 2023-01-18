import * as constants from './constants.js';
import { Input } from './input.js';


export class Player{
    constructor(xIni, yIni){
        this.x = xIni;
        this.y = yIni;
        this.vx = constants.VX;
        this.vy = constants.VY;
        this.vie = constants.VIE;
        this.score = 0;
        this.lastShotTime = 0;
        this.agonie = 0;
        this.Tballe = constants.TBALLE;
        this.Vballe = constants.VBALLE;
        this.image = new Image();
        this.image.src = constants.player_sprite.src;
    }

    getX() {return this.x;}
    getY() {return this.y;}
    getVX() {return this.vx;}
    getVY() {return this.vy;}
    getHauteur() {return this.image.height;}
    getLongueur() {return this.image.width;}

    update(){
        if (!this.estVivant()) return;
        if (Input.LEFT) {
            this.deplacer(-this.getVX(),0)
            //this.useImg(constants._HAUT); TODO
            //this.setOrientation(HAUT); TODO
        }
        else if (Input.RIGHT) {
            this.deplacer(this.getVX(),0)
            //this.useImg(constants._HAUT); TODO
            //this.setOrientation(HAUT);            
        }
        else if (Input.UP) {
            this.deplacer(0, -this.getVY())
            //this.useImg(constants._HAUT); TODO
            //this.setOrientation(HAUT);             
        }
        else if (Input.DOWN) {
            this.deplacer(0, this.getVY())
            //this.useImg(constants._HAUT); TODO
            //this.setOrientation(HAUT); 
        }
    }

    setOrientation(orientation) {this.orientation = orientation;}

    applyBonus (typeBonus){
        if (typeBonus == constants._VITESSE_PLUS){
            this.vx = this.vx + 2;
            this.vy = this.vy + 2;

        }
        else if (typeBonus == constants._VITESSE_MOINS){
            this.vx = this.vx - 1;
            this.vy = this.vy - 1;
            if (this.vx<1 || this.vy<1) {
                this.vx = 1;
                this.vy = 1;
            }
        }
        else if (typeBonus == constants._VIE_PLUS){
            this.vie += 20;
        }
        else if (typeBonus == constants._VIE_MOINS){
            this.vie -= 10;
        }
        else if (typeBonus == constants._VITESSE_BALLE_PLUS){
            this.Vballe += 5;
        }
        else if (typeBonus == constants._VITESSE_BALLE_MOINS){
            this.Vballe -= 2;
        }
    }

    estVivant(){
        if (this.vie <= 0){
            return false;
        }
        else{
            return true;
        }
    }

    deplacer(vx, vy){
        if (this.x+vx > 0 && this.x+vx+this.getLongueur() < constants.LONGUEUR) {
            this.x += vx;
        }
        if (this.y+vy > 0 && this.y+vy+this.getHauteur() < constants.LARGEUR) {
            this.y += vy;
        }
    }

    etreTouche(degats){
        this.vie = this.vie - degats;
    }

    initialisationPos(xini, yini){
        this.x = xini;
        this.y = yini;
    }
/*TODO
    setImg(SDL_Surface *imgH, SDL_Surface *imgB, SDL_Surface *imgG, SDL_Surface *imgD, SDL_Surface *imgDead){
        this->imgH = imgH;
        this->imgB = imgB;
        this->imgG = imgG;
        this->imgD = imgD;
        this->imgDead = imgDead;
    }*/

    /*TODO
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
    }*/

/*  TODO
      tirer(SDL_Surface *imgballeV, SDL_Surface *imgballeH){
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
    }*/


}

















