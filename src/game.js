import * as constants from './constants.js';
import { Player } from './player.js';
import { Balle } from './balle.js';

export const Game = {
  canvas : null,
  ctx : null,
  players : [],
  create : function(canvas){
    let game = Object.create(this);
    game.canvas = canvas;
    game.ctx = canvas.getContext('2d');
    this.players[0] = new Player(constants.PLAYER_0, 100, 100);
    this.players[1] = new Player(constants.PLAYER_1, 100, 500);
    Balle.imgballeV.src = constants.balle_sprites["VERTICALE"].src;
    Balle.imgballeH.src = constants.balle_sprites["HORIZONTALE"].src;

    return game;
  },
  update : function(){
    // Update players positions and actions
    this.players.forEach(player => player.update());
    this.players.forEach(player => player.balles.forEach(balle => balle.deplacerBalle()));
  },
  draw : function(){
    // Store the current transformation matrix
    this.ctx.save();

    // Use the identity matrix while clearing the canvas
    this.ctx.setTransform(1, 0, 0, 1, 0, 0);
    this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);

    // Restore the transform
    this.ctx.restore();
    // Fill background with black
    this.ctx.rect(0, 0, this.canvas.width, this.canvas.height);
    this.ctx.fill();

    // sprite render
    this.players.forEach(player => {
      if (!player.getImg()) return;
      this.ctx.drawImage(
        player.getImg(),
        player.getX(),
        player.getY());
        player.balles.forEach(b => {
          if (!b.getImg()) return;
          this.ctx.drawImage(
            b.getImg(),
            b.getX(),
            b.getY());
        });
    });
  }
}


