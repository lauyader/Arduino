/*
 HC-SR04 Ping distance sensor:
 VCC to arduino 5v 
 GND to arduino GND
 Echo to Arduino pin 7 
 Trig to Arduino pin 8
 
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */


#define echoPin 5 // Echo Pin
#define trigPin 4 // Trigger Pin
#define LEDPin 7 // Onboard LED

int maximumRange = 1000; // Maximum range needed
int minimumRange = 0; // Minimum range needed
float duration; // Duration used to calculate distance
float distance;
int IN2 = 11;
int IN1 =12;
int IN3 = 10; 
int IN4 = 9;


void setup() {
 Serial.begin (9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
 
 
   // Activacion de los pines de los motores
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 9 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 10
  pinMode (IN2, OUTPUT);    // Input2 conectada al pin 11
  pinMode (IN1, OUTPUT);    // Input1 conectada al pin 12 
  
}

void loop() {
/* The following trigPin/echoPin cycle is used to determine the
 distance of the nearest object by bouncing soundwaves off of it. */ 
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 

 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10); 
 
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 
 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;
 
 if (distance >= maximumRange || distance <= minimumRange){
 /* Send a negative number to computer and Turn LED ON 
 to indicate "out of range" */
 
 Serial.println("-1");
 Serial.println(distance);
 digitalWrite(LEDPin, HIGH); 
 //Serial.println("off");
 //Serial.begin (9600);
 
 
  // Motor gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW);
 }
 else {
 /* Send the distance to the computer using Serial protocol, and
 turn LED OFF to indicate successful reading. */
 
 Serial.println(distance);
 digitalWrite(LEDPin, LOW);
  if(distance >= 20) {

       // Motor gira en un sentido contrario
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH); 
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, HIGH);
  
  digitalWrite(LEDPin, HIGH);
  }
  else
  /*
  // Motor no gira
  digitalWrite (IN4, LOW);
  digitalWrite (IN2, LOW); 
  delay(5000);*/
  

  
  
     // Motor gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW); 
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW);
  
  
 
  
 }
 
 // 50ms before next reading.
 delay(50);
}
