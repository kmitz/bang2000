import * as constants from './constants.js';
import { globals } from './globals.js';
import { Player } from './player.js';
import { Balle } from './balle.js';
import { Obstacle } from './obstacle.js';
import { Bonus } from './bonus.js';

export const Game = {
  canvas : null,
  ctx : null,
  players : [],
  obstacles : [],
  bonus : [],
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
    if (globals.nb_tir > constants._NB_TIR_BONUS) {
      globals.nb_tir = 0;
      this.bonus.push(new Bonus());
    }
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
    });
    this.bonus.forEach(b => {
        this.ctx.drawImage(
          b.getImg(),
          b.getX(),
          b.getY());
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
        this.obstacles.forEach(obstacle => {
          if (this.hasCollision(
            balle.getY(),
            balle.getX(),
            balle.getY() + balle.getHauteur(),
            balle.getX() + balle.getLongueur(),
            obstacle.getY(),
            obstacle.getX(),
            obstacle.getY() + obstacle.getHauteur(),
            obstacle.getX() + obstacle.getLongueur()
          )) {
            const index = shooter.balles.indexOf(balle);
            shooter.balles.splice(index, 1);
          }
        })
      })
    })
    this.players.forEach(player => {
      this.bonus.forEach(b => {
          if (this.hasCollision(
            b.getY(),
            b.getX(),
            b.getY() + b.getHauteur(),
            b.getX() + b.getLongueur(),
            player.getY(),
            player.getX(),
            player.getY() + player.getHauteur(),
            player.getX() + player.getLongueur()
          )) {
            if (b.m_typeBonus == constants._BONUS_BLITZ){
                this.players.forEach(p => {
                    p.setVX(constants._VX_BLITZ);
                    p.setVX(constants._VY_BLITZ);
                    p.setVballe(constants._VBALLE_BLITZ);
                    p.setTballe(constants._TBALLE_BLITZ);
                });
            }
            else if (b.m_typeBonus == constants._BONUS_FREEZE){
                this.players.forEach(p => {
                    p.setVX(constants._VX_FREEZE);
                    p.setVX(constants._VY_FREEZE);
                    p.setVballe(constants._VBALLE_FREEZE);
                    p.setTballe(constants._TBALLE_FREEZE);
                });
            }
            else {
                player.applyBonus(b.m_typeBonus);
            }
            const index = this.bonus.indexOf(b);
            this.bonus.splice(index, 1);
          }
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


