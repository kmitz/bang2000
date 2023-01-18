import { Player } from './player.js';

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
    return game;
  },
  update : function(){
    // Update players positions and actions
    this.player.update();
  },
  draw : function(){
    // Store the current transformation matrix
    this.ctx.save();

    // Use the identity matrix while clearing the canvas
    this.ctx.setTransform(1, 0, 0, 1, 0, 0);
    this.ctx.clearRect(0, 0, this.canvas.width, this.canvas.height);

    // Restore the transform
    this.ctx.restore();

    // sprite render
    if (!this.player.getImg()) return;
    this.ctx.drawImage(
      this.player.getImg(),
      this.player.getX(),
      this.player.getY());
  },
}


