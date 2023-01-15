const sprite_data =       {
        src : 'Jbas.bmp',
        width : 33,
        height : 94,
        y : 0,
        numberOfFrames : 1,
        ticksPerFrame : 100,
        scale : 1
      };


export const Game = {
  canvas : null,
  ctx : null,
  world : null,
  image : null,
  create : function(canvas){
    let game = Object.create(this);
    game.canvas = canvas;
    game.ctx = canvas.getContext('2d');
    this.image = new Image();
    this.image.src = './assets/Jbas.bmp';
    this.image.width = sprite_data.width;
    this.image.height = sprite_data.height;
    this.image.scale = sprite_data.scale;
    return game;
  },
  update : function(){
    // Update players positions and actions
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

      this.ctx.drawImage(
                  this.image,
                  0,
                  0,
                  this.image.width,
                  this.image.height,
                  100, //x
                  100, //y
                  this.image.scale*this.image.width,
                  this.image.scale*this.image.height);
  },
}


