// Internetdelascosas.cl
// Script para leer temperatura utilizando un LM35

// Declaracion de variables
float irC;
int irPin = 0; // Definimos la entrada en pin A0
int led = 13;
void setup()
{
  pinMode(led, OUTPUT);  
  // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
    
}
void loop()
{
    // Lee el valor desde el sensor
    irC = analogRead(irPin); 

    // Convierte el valor a temperatura
   // tempC = (5.0 * tempC * 100.0)/1024.0; 

    // Envia el dato al puerto serial
    Serial.print(irC);
    Serial.print(" mm\n");
    
    if (irC <= 16){ 
      Serial.print("Paso Alguien: ");
        digitalWrite(led, HIGH);
        
  
        }
digitalWrite(led, LOW);
      
        // all are correct

    // Espera cinco segundo para repetir el loop
    delay(500);
}
