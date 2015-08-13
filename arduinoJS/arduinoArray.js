var five = require("johnny-five");
var board = new five.Board();

board.on("ready", function() {
  var array = new five.Leds([3, 5, 6]);

  array.pulse();
});

