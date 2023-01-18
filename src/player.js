import * as constants from './constants.js';
import { Input } from './input.js';
import { Balle } from './balle.js';


export class Player{
    constructor(xIni, yIni){
        this.x = xIni;
        this.y = yIni;
        this.vx = constants.VX;
        this.vy = constants.VY;
        this.vie = constants.VIE;
        this.score = 0;
        this.lastShotTime = Date.now();
        this.agonie = 0;
        this.Tballe = constants.TBALLE;
        this.Vballe = constants.VBALLE;
        this.imgH = new Image();
        this.imgH.src = constants.player_sprites["HAUT"].src;
        this.imgB = new Image();
        this.imgB.src = constants.player_sprites["BAS"].src;
        this.imgG = new Image();
        this.imgG.src = constants.player_sprites["GAUCHE"].src;
        this.imgD = new Image();
        this.imgD.src = constants.player_sprites["DROITE"].src;
        this.img = new Image();
        this.useImg(constants._DROITE);
        this.orientation = constants._DROITE;
        this.balles = [];
    }

    getX() {return this.x;}
    getY() {return this.y;}
    getVX() {return this.vx;}
    getVY() {return this.vy;}
    getImg(){return this.img;}
    getHauteur() {return this.img.height;}
    getLongueur() {return this.img.width;}
    getVballe() {return this.Vballe;};
    setVballe(vitesse) {this.Vballe = vitesse;}
    getTballe() {return this.Tballe;};
    setTballe(tps) {this.Tballe = tps;}

    update(){
        if (!this.estVivant()) return;
        if (Input.LEFT) {
            this.deplacer(-this.getVX(),0)
            this.useImg(constants._GAUCHE); 
            this.orientation = constants._GAUCHE;
        }
        else if (Input.RIGHT) {
            this.deplacer(this.getVX(),0)
            this.useImg(constants._DROITE); 
            this.orientation = constants._DROITE;
        }
        else if (Input.UP) {
            this.deplacer(0, -this.getVY())
            this.useImg(constants._HAUT); 
            this.orientation = constants._HAUT;
        }
        else if (Input.DOWN) {
            this.deplacer(0, this.getVY())
            this.useImg(constants._BAS); 
            this.orientation = constants._BAS;
        }
        if (Input.SPACE) this.tirer();
    }

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

    useImg(val){
        if (val == constants._HAUT){
            this.img.src = this.imgH.src;
        }
        else if (val == constants._BAS){
            this.img.src = this.imgB.src;
        }
        else if (val == constants._GAUCHE){
            this.img.src = this.imgG.src;
        }
        else if (val == constants._DROITE){
            this.img.src = this.imgD.src;
        }
        else if (val == constants._DEAD){
            this.img.src = this.imgDead.src;
        }
    }

    tirer(){
        const presentTime = Date.now();

        if (presentTime - this.lastShotTime > this.Tballe) {
            const balle = new Balle(this.orientation,this.x, this.y, this.Vballe);
            this.balles.push(balle);

            this.lastShotTime = Date.now();
            return true;
        }
        else return false;
    }

}

















