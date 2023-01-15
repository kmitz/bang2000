
setTimeout(() => {

let canvas = document.getElementById("canvas-mmo");
let ctx_mmo = canvas.getContext('2d');


let image = document.getElementById("source")

ctx_mmo.drawImage(image, 300,0);
}, 1000);
