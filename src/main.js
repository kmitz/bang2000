import { Game } from './game.js';
import { Input } from './input.js';
import { LONGUEUR, HAUTEUR } from './constants.js';



let padding = 20; //pixels

let canvas = document.getElementById("my-canvas");


const run = () => {
    game.update();
    game.draw();
    id_animation_frame = window.requestAnimationFrame(run);
};

let id_animation_frame;

let game = Game.create(canvas);

setTimeout(() =>{ run(); }, 1000);

canvas.width = LONGUEUR;
canvas.height = HAUTEUR;

Input.applyEventHandlers(canvas);

