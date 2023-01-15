export const Sprite = {
    frameIndex : 0,
    y : 0,
    tickCount : 0,
    ticksPerFrame : 0,
    numberOfFrames : 1,
    context : null,
    image : null,
    width : null,
    height : null,
    scale : 1,
    freezeLastFrame : null,
    loopAnimation : null,
    isAnimated : null, // true for single image sprite, otherwise false

    create : function(options) {
        let sprite = Object.create(this);
        sprite.context = options.context;
        sprite.ticksPerFrame = options.sprite_data.ticksPerFrame,
        sprite.numberOfFrames = options.sprite_data.numberOfFrames;
        sprite.width = options.sprite_data.width;
        sprite.height = options.sprite_data.height;
        sprite.y = options.sprite_data.y || 0;
        sprite.image = new Image();
        sprite.image.src = options.sprite_data.src;
        sprite.scale = options.sprite_data.scale || 1;
        sprite.loopAnimation = options.sprite_data.loopAnimation;
        sprite.freezeLastFrame = options.sprite_data.freezeLastFrame;
        sprite.isAnimated = options.sprite_data.isAnimated === false ? false : true;
        return sprite;
    },    

    update : function () {
        if (!this.isAnimated) return;

        this.tickCount += 1;

        if (this.tickCount > this.ticksPerFrame) {

            this.tickCount = 0;
            
            // If the current frame index is in range
            if (this.frameIndex < this.numberOfFrames - 1) {  
                // Go to the next frame
                this.frameIndex += 1;
            } else {
                if (!this.loopAnimation) return;
                this.frameIndex = 0;
            }
        }
    },
    switchTo : function(sprite_data){
        this.ticksPerFrame = sprite_data.ticksPerFrame || 0,
        this.numberOfFrames = sprite_data.numberOfFrames || 1;
        this.width = sprite_data.width;
        this.height = sprite_data.height;
        this.y = sprite_data.y || 0;
        this.scale = sprite_data.scale;    
        this.frameIndex = 0;   
        this.image.src = sprite_data.src;
        this.loopAnimation = sprite_data.loopAnimation;
        this.freezeLastFrame = sprite_data.freezeLastFrame;
    },
    
    render : function (x, y) {
        if (!this.isAnimated){
            this.context.drawImage(
                this.image,
                0,
                this.y,
                this.width,
                this.height,
                x,
                y,
                this.scale*this.width,
                this.scale*this.height);
        }
        else {
            // Draw the animation
            this.context.drawImage(
                this.image,
                this.frameIndex * this.width/ this.numberOfFrames,
                this.y,
                this.width / this.numberOfFrames,
                this.height,
                x,
                y,
                this.scale*this.width / this.numberOfFrames,
                this.scale*this.height);
        }
    },
}

