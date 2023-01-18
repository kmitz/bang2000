import * as constants from './constants.js';

export class Balle
{
    static imgballeV = new Image();
    static imgballeH = new Image();
    constructor(orientation, x, y, Vballe)
    {
        this.img = new Image();
        this.orientation = orientation;
        if(orientation == constants._HAUT){
            this.x = x + 30;
            this.y = y;
            this.vy = -Vballe;
            this.vx = 0;
            this.useImg(Balle.imgballeV);
        }

        else if(orientation == constants._BAS){
            this.x = x + 12;
            this.y = y + 60;
            this.vy = Vballe;
            this.vx = 0;
            this.useImg(Balle.imgballeV);
        }

        else if(orientation == constants._DROITE){
            this.x = x + 54;
            this.y = y + 28;
            this.vy = 0;
            this.vx = Vballe;
            this.useImg(Balle.imgballeH);
        }

        else if(orientation == constants._GAUCHE){
            this.x = x;
            this.y = y + 28;
            this.vy = 0;
            this.vx = -Vballe;
            this.useImg(Balle.imgballeH);
        }
        this.degats = constants.DEGATS;
    }

    getX() {return this.x;}
    getY() {return this.y;}
    getOrientation() {return this.orientation;}
    getDegats() {return this.degats;}
    useImg(img) {this.img.src = img.src;}
    getImg() {return this.img;}
    getHauteur() {return this.img.height;}
    getLongueur() {return this.img.width;}

    deplacerBalle()
    {
        this.x += this.vx;
        this.y += this.vy;

    }

};



