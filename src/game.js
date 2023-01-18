import * as constants from './constants.js';
import { Player } from './player.js';
import { Balle } from './balle.js';

export const Game = {
  canvas : null,
  ctx : null,
  image : null,
  player : null,
  create : function(canvas){
    let game = Object.create(this);
    game.canvas = canvas;
    game.ctx = canvas.getContext('2d');
    this.player = new Player(100, 100);
    Balle.imgballeV.src = constants.balle_sprites["VERTICALE"].src;
    Balle.imgballeH.src = constants.balle_sprites["HORIZONTALE"].src;

    return game;
  },
  update : function(){
    // Update players positions and actions
    this.player.update();
    this.player.balles.forEach(b => b.deplacerBalle());
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
    if (!this.player.getImg()) return;
    this.ctx.drawImage(
      this.player.getImg(),
      this.player.getX(),
      this.player.getY());
    this.player.balles.forEach(b => {
      if (!b.getImg()) return;
      this.ctx.drawImage(
        b.getImg(),
        b.getX(),
        b.getY());
    });

  },
}


