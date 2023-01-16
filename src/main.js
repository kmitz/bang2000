import { Game } from './game.js';
import { Input } from './input.js';
import { WORLD_WIDTH, WORLD_HEIGHT } from './constants.js';


let padding = 20; //pixels

let canvas_mmo = document.getElementById("canvas-mmo");
let ctx_mmo = canvas_mmo.getContext('2d');


const run = () => {
    game.update();
    game.draw();
    id_animation_frame = window.requestAnimationFrame(run);
};

let id_animation_frame;

let game = Game.create(canvas_mmo);

    setTimeout(() =>{ run(); }, 1000);

// On veut maximiser hauteur et largeur de la scène
// tout en conservant le ratio et sans tronquer.
// Donc on redimensionne le canvas et on fait une mise
// à l'échelle selon ces critères
const resizeAndScaleCanvas = (canvas, ctx) => {
    const view_width = window.innerWidth;
    const view_height = window.innerHeight - padding;
    // NB : Le resize du canvas réinitialise la matrice de transformation
    // Il faut d'abord redimensionner le canvas, puis appliquer la mise à l'échelle
    // et la translation

    // Sauvegarde de la translation (panning horizontal de la scène);
    // On prend en compte le Pixel ratio afficher un rendu haute définition sur les smartphones.
    // La taille du canvas est multiplié par le pixel ratio,, puis le rendu est adapté à la vue
    // via application d'un style CSS.
    // Source : https://www.html5rocks.com/en/tutorials/canvas/hidpi/
    const dpr = window.devicePixelRatio || 1;
    const scale_factor = dpr * view_height / WORLD_HEIGHT;
    canvas.width = view_width * dpr;
    canvas.height = view_height * dpr;

    // Translation pour centrer le jeu sur le canvas + prendre en compte le panning
    // WARNING : l'ordre des opérations est important : d'abord translation puis mise à l'échelle
    // https://stackoverflow.com/questions/11332608/understanding-html-5-canvas-scale-and-translate-order
    const offset_x = game ? game.offset_x : 0;
    const shift_x = -(view_height / WORLD_HEIGHT * (WORLD_WIDTH - offset_x) - window.innerWidth)*dpr/2;
    ctx.translate(shift_x,0);
    
    // Scale all drawing operations by the dpr, so you don't have to worry about the difference.
    ctx.scale(scale_factor, scale_factor);

    // On adapte la taille du canvas à la taille de l'écran
    canvas.style.width = view_width;
    canvas.style.height = view_height;
}

// resize the canvas to fill browser window dynamically
window.addEventListener('resize', () => resizeAndScaleCanvas(canvas_mmo, ctx_mmo), false);

resizeAndScaleCanvas(canvas_mmo, ctx_mmo);

Input.applyEventHandlers(canvas_mmo);

