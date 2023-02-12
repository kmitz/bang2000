import * as constants from './constants.js';
import { Player } from './player.js';
import { Balle } from './balle.js';
import { Obstacle } from './obstacle.js';

export const Game = {
  canvas : null,
  ctx : null,
  players : [],
  obstacles : [],
  create : function(canvas){
    let game = Object.create(this);
    game.canvas = canvas;
    game.ctx = canvas.getContext('2d');
    this.players[0] = new Player(100, 100, constants.PLAYER_0);
    this.players[1] = new Player(100, 500, constants.PLAYER_1);
    Balle.imgballeV.src = constants.balle_sprites["VERTICALE"].src;
    Balle.imgballeH.src = constants.balle_sprites["HORIZONTALE"].src;
    for (let i=0; i <constants._NB_OBSTACLES; i++){
      this.obstacles.push(new Obstacle());
    }
    return game;
  },
  update : function(){
    // Update players positions and actions
    this.players.forEach(player => player.update());
    this.players.forEach(player => player.balles.forEach(balle => balle.deplacerBalle()));
    // Effacement des balles qui sortent du terrain de jeu
    this.players.forEach(player => player.balles.forEach(balle => {
      if (balle.getX() > constants.LONGUEUR
        || balle.getY() > constants.HAUTEUR
        || balle.getX() < 0
        || balle.getY() < 0){
        const index = player.balles.indexOf(balle);
        player.balles.splice(index, 1);
      }
    }));
    this.detectCollisions();
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
    this.obstacles.forEach(obstacle => {
        this.ctx.drawImage(
          obstacle.getImg(),
          obstacle.getX(),
          obstacle.getY());
    })
  },
  detectCollisions : function() {
    this.players.forEach(shooter => {
      shooter.balles.forEach(balle => {
        this.players.forEach(target => {
          if (shooter.id === target.id) return;
          if (this.hasCollision(
            balle.getY(),
            balle.getX(),
            balle.getY() + balle.getHauteur(),
            balle.getX() + balle.getLongueur(),
            target.getY(),
            target.getX(),
            target.getY() + target.getHauteur(),
            target.getX() + target.getLongueur()
          )) {
            target.etreTouche(balle.getDegats());
            shooter.augScore(balle.getDegats());
            const index = shooter.balles.indexOf(balle);
            shooter.balles.splice(index, 1);
          }
        })
      })
    })
  },
  hasCollision : function(top1,left1,bottom1,right1, top2, left2, bottom2, right2){
    if (right1 < left2){return false;}
    if (top1 > bottom2){return false;}
    if (bottom1 < top2){return false;}
    if (left1 > right2){return false;}
    else {return true;}
  }
}


