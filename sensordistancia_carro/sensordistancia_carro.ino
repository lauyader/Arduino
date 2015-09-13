// Internetdelascosas.cl
// Script para leer la distancia  utilizando un LM35

// Declaracion de variables
float dist;
int distPin = 0; // Definimos la entrada en pin A0
int distr = 0;
int led = 13;


// Declaraciones de variables para activar los motores

int input; 

int IN1 = 12; 
int IN2 = 11;
int IN3 = 10; 
int IN4 = 9;






void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
    
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
    delay(2000);
    // Lee el valor desde el sensor
    dist= analogRead(distPin);
     

    // Convierte el valor a temperatura
    //tempC = (5.0 * tempC * 100.0)/1024.0; 

    // Envia el dato al puerto serial
    Serial.print("  Estas a:  ");
    distr= dist/100;
    Serial.print(distr);
    Serial.print(dist / 100);
    Serial.print("  ctm  del objeto mas cercano\n ");
    if (distr <= 0.14)
    {
       Serial.print("  Obstaculo en la via no puedes continuar \n ");
        digitalWrite(led, HIGH);
        
         digitalWrite (IN4, LOW);
         digitalWrite (IN2, LOW); 
         digitalWrite (IN3, LOW); 
         digitalWrite (IN1, LOW);
         delay(1000);
;
         
 
         digitalWrite (IN4, LOW);
         digitalWrite (IN2, HIGH); 
         digitalWrite (IN3, HIGH); 
         digitalWrite (IN1, LOW);
         delay(2000);         
       
       

       
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
    // Espera cinco segundo para repetir el loop
    delay(500);
}

