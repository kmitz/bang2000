import { Game } from './game.js';
import { Input } from './input.js';
import { LONGUEUR, HAUTEUR } from './constants.js';


let canvas = document.getElementById("my-canvas");
canvas.width = LONGUEUR;
canvas.height = HAUTEUR;

let id_animation_frame;
const run = () => {
    game.update();
    game.draw();
    id_animation_frame = window.requestAnimationFrame(run);
};

let game = Game.create(canvas);

setTimeout(() =>{ run(); }, 1000); //TODO : find better solution to wait for assets (images,...) to load

Input.applyEventHandlers(canvas);

