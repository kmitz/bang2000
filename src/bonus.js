import * as constants from './constants.js';
import { Player } from './player.js';

export class Bonus extends Player{
    constructor(){
        super();
        this.m_typeBonus = Math.floor(Math.random()*(constants._NB_TYPE_BONUS) + 1);
        this.img = new Image();
        this.img.src = constants.bonus_sprite.IMG.src;
        this.initialisationPos(
            Math.floor(Math.random()*(constants.LONGUEUR-this.img.width - 1) + 1), 
            Math.floor(Math.random()*(constants.HAUTEUR-this.img.height - 1) + 1));
    }
}

















