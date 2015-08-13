var five = require("johnny-five");
var board = new five.Board();
board.on("ready", function() {
  // vamos a crear un LED en el pin 13 y a hacerlo parpadear por un segundo, el parametro que recibe son milisegundos
	var led13 = new five.Led(13); 
	var led7 = new five.Led(7); 
	var led2 = new five.Led(2); 
	var tecla prompt = ('Dame una letra:','');
	document.write(tecla);
  //(new five.Led(13)).strobe("1000");
	led13.strobe("1000");
	led7.strobe("1000");
	led2.strobe("1000");
});
