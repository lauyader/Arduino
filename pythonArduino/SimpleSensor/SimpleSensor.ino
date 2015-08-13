// these are the pins we will use for this sketch
#define POTENTIOMETER_PIN 0 // analog pin 0
#define LIGHT_SENSOR_PIN 2 // analog pin 2
#define BUTTON_PIN 2 // digital pin 2


// run this one on startup
void setup() {
  Serial.begin( 9600 );
  pinMode( BUTTON_PIN, INPUT );
}


// run this repeatedly forever (until Arduino is reset or unplugged)
void loop() {

  // read sensor values
  int potentiometer = analogRead( POTENTIOMETER_PIN );
  int light = analogRead( LIGHT_SENSOR_PIN );
  int button = digitalRead( BUTTON_PIN );

  // send to serial console
  Serial.print( potentiometer );
  Serial.print( "," );
  Serial.print( light );
  Serial.print( "," );
  Serial.print( button );
  Serial.println(); // end of line

  // sleep for 200 milliseconds
  delay( 200 );
}
