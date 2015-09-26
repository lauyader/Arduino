
void setup() {                

  

  // Se debe conectar el Laser a la salida Digital 13

  pinMode(13, OUTPUT);     

}

 

void loop() {

  digitalWrite(13, HIGH);   // Enciende el Laser

  delay(100);              // Espera 0.1 segundos

  digitalWrite(13, LOW);    // Apaga el Laser

  delay(100);              // Espera 0.1 segundos

}

// by Ale DC

 
