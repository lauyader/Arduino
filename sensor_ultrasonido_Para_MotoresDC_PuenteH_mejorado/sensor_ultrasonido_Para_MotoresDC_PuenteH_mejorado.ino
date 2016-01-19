/*
 HC-SR04 Ping distance sensor:
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
#define led 13
#define led2 2
 

int IN2 = 10;
int IN1 =11;
int IN3 = 9; 
int IN4 = 8;

void setup()
{
  
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  /*
  */ 
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  
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

  delayMicroseconds(1000); //- Removed this line

//  delayMicroseconds(20); // Added this line

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;
  Serial.println(distance); 

   digitalWrite(led, LOW);
   digitalWrite(led2, HIGH);
  // CONDICIÓN CUANDO SE ENCUENTRA A MENOR DISTANCIA DEL OBSTACULO

  if (distance < 5) {  // This is where the LED On/Off happens
     
     Serial.println(distance);
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(led2, LOW);
         if (distance==0.00){
               Serial.println("llego a cero");
               digitalWrite(led, LOW);
               digitalWrite(led2, LOW);
                
             }
  
 
 
        // Motor retrocede
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  Serial.println("Menor distancia:");
  Serial.println("Encender Motores traseros en retroceso");
  //Cruzan las ruedas delanteras
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW);
  delay(150);

 
}

  else {

//    digitalWrite(led2,HIGH);
    //digitalWrite(Pin, LOW);
    
      // Motor gira en un sentido hacia adelante Rueda de Empuje traseras
      digitalWrite (IN4, LOW);
      digitalWrite (IN3, HIGH); 
      
        //Cruzan las ruedas delanteras
        
        digitalWrite (IN2, LOW);
        digitalWrite (IN1, HIGH);
        
        delay(150);
        
       // digitalWrite (IN2, LOW);
       // digitalWrite (IN1, HIGH); 
  
  }
  
/*
  if (distance >= 100){
    digitalWrite(led2, HIGH);

    Serial.println("Out of range");
    digitalWrite(trigPin, LOW);
    
    //digitalWrite(Pin, HIGH);
    //pinMode(reset, OUTPUT);
    //Serial.begin(9600);
    //Serial.println("Reset");
    //delay(200);
    

  }
*/
  /*else {

    Serial.print(distance);

    Serial.println(" cm");
*/




  delay(500);
 
}

