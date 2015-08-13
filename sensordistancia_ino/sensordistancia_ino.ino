// Internetdelascosas.cl
// Script para leer la distancia  utilizando un LM35

// Declaracion de variables
float dist;
int distPin = 0; // Definimos la entrada en pin A0
int distr = 0;
int led = 12;
void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
    
    // Activa el pin 12
    pinMode(led, OUTPUT);
}
void loop()
{
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
    }
    else 
    {
    Serial.print("  puedes continuar \n");
    digitalWrite(led, LOW);
    }
    // Espera cinco segundo para repetir el loop
    delay(500);
}

