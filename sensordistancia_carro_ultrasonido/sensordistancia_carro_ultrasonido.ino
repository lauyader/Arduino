// Internetdelascosas.cl
// Script para leer la distancia  utilizando un LM35





 

// Declaraciones de variables para activar los motores

int input; 

int IN1 = 12; 
int IN2 = 11;
int IN3 = 10; 
int IN4 = 9;
int trigPin=8;
int echoPin=7;
int led = 5;
int led2 = 4;





void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
    
    
      //Sensor de Ultrasonido
  pinMode(trigPin, OUTPUT);  // Dispara el sonido
  pinMode(echoPin, INPUT);   // Recoge el eco del sonido disparado
  pinMode(led, OUTPUT);         
  pinMode(led2, OUTPUT);
    
    // Activa el pin 12
    pinMode(led, OUTPUT);
    
  pinMode (IN1, OUTPUT);    // Input4 conectada al pin 12 
  pinMode (IN2, OUTPUT);    // Input3 conectada al pin 11
  pinMode (IN3, OUTPUT);    // Input4 conectada al pin 10
  pinMode (IN4, OUTPUT);    // Input3 conectada al pin 9
  

  
    
}
void loop()
{
    
    // Tiempo de espera despues que conecta a la corriente
    
    
    // CODIGO DE ULTRASONIDO
  long duration, distance;

  digitalWrite(trigPin, LOW);  // Added this line

  delayMicroseconds(2); // Added this line

  digitalWrite(trigPin, HIGH);

//  delayMicroseconds(1000); - Removed this line

  delayMicroseconds(10); // Added this line

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;
            
            
            //Serial.print(distance);
            
  if (distance < 4) {  // This is where the LED On/Off happens

    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off

  digitalWrite(led2,LOW);

}

  else {

    digitalWrite(led,LOW);

    digitalWrite(led2,HIGH);

  }

  if (distance >= 200 || distance <= 0){

    Serial.println("Out of range");

  }

  else {

    Serial.print(distance);

    Serial.println(" cm");

  }
           
            
            
    // FIN DEL SENSOR ULTRASONIDO
    
    
 
 
    
    /*
     if (distance < 4)
    {
       Serial.print("  Obstaculo en la via no puedes continuar \n ");
        digitalWrite(led, HIGH);
        
         digitalWrite (IN4, LOW);
         digitalWrite (IN2, LOW); 
         digitalWrite (IN3, LOW); 
         digitalWrite (IN1, LOW);
         delay(1000);

         
       /*
         digitalWrite (IN4, LOW);
         digitalWrite (IN2, HIGH); 
         digitalWrite (IN3, HIGH); 
         digitalWrite (IN1, LOW);
         delay(2000);         
       */
       
    /*
       
    }
    else 
    {
    Serial.print("  puedes continuar \n");
    digitalWrite(led, LOW);
    
 
    
    
         digitalWrite (IN4, HIGH);
         digitalWrite (IN3, LOW); 
         digitalWrite (IN2, LOW); 
         digitalWrite (IN1, HIGH);
    

        
    }
    
*/
    delay(500);
    
    
    
    
    
    
}

