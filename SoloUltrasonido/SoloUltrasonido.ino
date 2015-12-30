/*
 HC-SR04 Ping distance sensor]
 VCC to arduino 5v GND to arduino GND
 Echo to Arduino pin 13 Trig to Arduino pin 12
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 More info at: http://goo.gl/kJ8Gl
 Original code improvements to the Ping sketch sourced from Trollmaker.com
 Some code and wiring inspired by http://en.wikiversity.org/wiki/User:Dstaub/robotcar
 */



#define trigPin 7

#define echoPin 6

#define led 9

#define led2 8

#define Pin 5



int reset = 10;

void setup() {

  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);

  pinMode(echoPin, INPUT);

  pinMode(led, OUTPUT);

  pinMode(led2, OUTPUT);
  
  pinMode(Pin, OUTPUT);
  
  

}



void loop() {

  float duration, distance;

  digitalWrite(trigPin, LOW);  // Added this line

  delayMicroseconds(2); // Added this line

  digitalWrite(trigPin, HIGH);

//  delayMicroseconds(1000); - Removed this line

  delayMicroseconds(10); // Added this line

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;

  if (distance < 4) {  // This is where the LED On/Off happens

    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off

  digitalWrite(led2,LOW);

}

  else {

    digitalWrite(led,LOW);

    digitalWrite(led2,HIGH);
    digitalWrite(Pin, LOW);
  }

  if (distance >= 200 || distance <= 0){

    Serial.println("Out of range");
    digitalWrite(trigPin, LOW);
    
    digitalWrite(Pin, HIGH);
    //pinMode(reset, OUTPUT);
    //Serial.begin(9600);
    //Serial.println("Reset");
    //delay(200);
    

  }

  else {

    Serial.print(distance);

    Serial.println(" cm");

  }

  delay(500);

}
