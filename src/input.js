/**
 * Empty constructor for the Input object.
 */
let Input = function() {
  throw new Error('Input should not be instantiated!');
}

/** @type {boolean} */
Input.LEFT = false;
/** @type {boolean} */
Input.UP = false;
/** @type {boolean} */
Input.RIGHT = false;
/** @type {boolean} */
Input.DOWN = false;
/** @type {boolean} */
Input.ENTER = false;
/** @type {boolean} */
Input.SPACE = false;
/** @type {boolean} */
Input.F = false;
Input.B = false;
Input.G = false;
Input.T = false;
/** @type {Object<number, boolean>} */
Input.MISC_KEYS = {};

/**
 * This method is a callback bound to the onkeydown event on the document and
 * @param {Event} event The event passed to this function.
 * updates the state of the keys stored in the Input class.
 */
Input.onKeyDown = function(event) {
  switch (event.keyCode) {
    case 37:
    case 65:
      Input.LEFT = true;
      break;
    case 38:
    case 87:
      Input.UP = true;
      break;
    case 39:
    case 68:
      Input.RIGHT = true;
      break;
    case 40:
    case 83:
      Input.DOWN = true;
      break;
    case 13:
      Input.ENTER = true;
      break;
    case 32:
      Input.SPACE = true;
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
      Input.MISC_KEYS[event.keyCode] = true;
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
      Input.LEFT = false;
      break;
    case 38:
    case 87:
      Input.UP = false;
      break;
    case 39:
    case 68:
      Input.RIGHT = false;
      break;
    case 40:
    case 83:
      Input.DOWN = false;
      break;
    case 13:
      Input.DOWN = false;
      break;
    case 32:
      Input.SPACE = false;
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
      Input.MISC_KEYS[event.keyCode] = false;
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

export { Input };