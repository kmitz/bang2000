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

let gameHasStarted = false;
let isGameReady = false; // hack pour attendre le chargement des assets

document.addEventListener('keydown', (event) => {
    if(event.keyCode === 13 && !gameHasStarted && isGameReady) {
        gameHasStarted = true;
        let audioElement = document.createElement('audio');
        audioElement.setAttribute('src', `assets/Round_1_Streets_of_Rage_Music.MP3`);
        audioElement.loop = true;
        audioElement.play();
        document.querySelector(".start-message").style.display='none';
        run();
    }
});


setTimeout(() =>{ isGameReady = true; }, 1000); //TODO : find better solution to wait for assets (images,...) to load



Input.applyEventHandlers(canvas);

