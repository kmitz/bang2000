import * as constants from './constants.js';

/**
 * Empty constructor for the Input object.
 */
export let Input = function() {
  throw new Error('Input should not be instantiated!');
}

export let player_inputs = {
    [constants.PLAYER_0] : {
        "LEFT" : false,
        "RIGHT" : false,
        "UP" : false,
        "DOWN" : false,
        "SHOOT" : false,
    },
    [constants.PLAYER_1] : {
        "LEFT" : false,
        "RIGHT" : false,
        "UP" : false,
        "DOWN" : false,
        "SHOOT" : false,
    },
    [constants.PLAYER_2] : {
        "LEFT" : false,
        "RIGHT" : false,
        "UP" : false,
        "DOWN" : false,
        "SHOOT" : false,
    },
    [constants.PLAYER_3] : {
        "LEFT" : false,
        "RIGHT" : false,
        "UP" : false,
        "DOWN" : false,
        "SHOOT" : false,
    },
}

/**
 * This method is a callback bound to the onkeydown event on the document and
 * @param {Event} event The event passed to this function.
 * updates the state of the keys stored in the Input class.
 */
Input.onKeyDown = function(event) {
  switch (event.keyCode) {
    case 37:
    case 65:
      player_inputs[constants.PLAYER_0].LEFT = true;
      break;
    case 38:
    case 87:
      player_inputs[constants.PLAYER_0].UP = true;
      break;
    case 39:
    case 68:
      player_inputs[constants.PLAYER_0].RIGHT = true;
      break;
    case 40:
    case 83:
      player_inputs[constants.PLAYER_0].DOWN = true;
      break;
    case 13:
      Input.ENTER = true;
      break;
    case 32:
      player_inputs[constants.PLAYER_0].SHOOT = true;
      break;
    case 70:
      Input.F = true;
    break;
    case 66:
      Input.B = true;
    break;
    case 71:
      Input.G = true;
    break;
    case 84:
      Input.T = true;
    break;
    default:
      //Input.MISC_KEYS[event.keyCode] = true;
      break;
  }
};

/**
 * This method is a callback bound to the onkeyup event on the document and
 * updates the state of the keys stored in the Input class.
 * @param {Event} event The event passed to this function.
 */
Input.onKeyUp = function(event) {
  switch (event.keyCode) {
    case 37:
    case 65:
      player_inputs[constants.PLAYER_0].LEFT = false;
      break;
    case 38:
    case 87:
      player_inputs[constants.PLAYER_0].UP = false;
      break;
    case 39:
    case 68:
      player_inputs[constants.PLAYER_0].RIGHT = false;
      break;
    case 40:
    case 83:
      player_inputs[constants.PLAYER_0].DOWN = false;
      break;
    case 13:
      Input.DOWN = false;
      break;
    case 32:
      player_inputs[constants.PLAYER_0].SHOOT = false;
      break;
    case 70:
      Input.F = false;
    break;
    case 66:
      Input.B = false;
    break;
    case 71:
      Input.G = false;
    break;
    case 84:
      Input.T = false;
    break;
    default:
      //Input.MISC_KEYS[event.keyCode] = false;
      break;
  }
};

/**
 * This should be called during initialization to allow the Input
 * class to track user input.
 * @param {Element} element The element to apply the event listener to.
 */
Input.applyEventHandlers = function(element) {
  element.setAttribute('tabindex', 0);
  element.addEventListener('keyup', Input.onKeyUp);
  element.addEventListener('keydown', Input.onKeyDown);
};

