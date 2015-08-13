int x = 0;    // variable

void setup() {
  Serial.begin(9600);      // abre el puerto serie a 9600 bps:
}

void loop() {

  Serial.println(random(-100, 100)); // Escribe en el puerto un numero aleatorio de -100 a 100
  delay(2000);
}
