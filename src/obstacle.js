import * as constants from './constants.js';
import { Player } from './player.js';

export class Obstacle extends Player{
    constructor(playerId, xIni, yIni){
        super();
        this.img = new Image();
        this.img.src = constants.obstacle_sprite.IMG.src;
        this.initialisationPos(
            Math.floor(Math.random()*(constants.LONGUEUR-this.img.width - 1) + 1), 
            Math.floor(Math.random()*(constants.HAUTEUR-this.img.height - 1) + 1));
    }
}

















