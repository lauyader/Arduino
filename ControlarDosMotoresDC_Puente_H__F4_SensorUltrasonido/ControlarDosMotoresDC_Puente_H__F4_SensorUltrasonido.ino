/* 
 Ejemplo de control de motor DC usando modulo L298
 http://electronilab.co/tienda/driver-dual-para-motores-full-bridge-l298n/
 
 El programa activa el motor en un sentido por 4 segundos, 
 para el motor por 500 ms, activa el motor en sentido inverso por 4 segundos 
 y se detiene por 5 segundos. Luego repite la acción indefinidamente.
 
 Creado 16/05/14
 por Andres Cruz
 ELECTRONILAB.CO
 */
 
 
 
// Variable del sensor ultrasonido 
#define trigPin 7
#define echoPin 6


int led2 = 5;
int led = 4;

int IN2 = 11;
int IN1 =12;
int IN3 = 10; 
int IN4 = 9;

void setup()
{
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  //Definir la salida del puente H
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 9 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 10
  pinMode (IN2, OUTPUT);    // Input2 conectada al pin 11
  pinMode (IN1, OUTPUT);    // Input1 conectada al pin 12 
}
void loop()
{
  // Esperar por la conexion
 // delay(3000);
 
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
    //digitalWrite(Pin, LOW);
  }

  if (distance >= 200 || distance <= 0){

    Serial.println("Out of range");
    digitalWrite(trigPin, LOW);
    
    //digitalWrite(Pin, HIGH);
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
 

 
 
 
 
 
 
 
 
 
/* 
 
  // Motor gira en un sentido hacia adelante Rueda de Empuje traseras
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, HIGH); 
  //digitalWrite (IN2, HIGH);
  //digitalWrite (IN1, LOW);
  delay(2000);
  
  
    // Motor gira en un sentido hacia atras Rueda de Empuje traseras
  //digitalWrite (IN4, HIGH);
  //digitalWrite (IN3, LOW); 
    delay(3000);
    
  digitalWrite (IN4, LOW);
  digitalWrite (IN3, LOW);   
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW);
  
  
  delay(500);
  
  digitalWrite (IN2, LOW);
  digitalWrite (IN1, HIGH);
  delay(500);
  /*
  // Motor no gira
  digitalWrite (IN4, LOW);
  digitalWrite (IN2, LOW); 
  delay(500);
  // Motor gira en sentido inverso
  digitalWrite (IN3, HIGH);
  delay(4000);
  // Motor no gira
  digitalWrite (IN3, LOW); 
  delay(5000);*/
  
}
