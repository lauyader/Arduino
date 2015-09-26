// Codigo para carro evasor de obstaculo


int mot1_izq=A3;
int mot1_der=A4;
int mot2_izq=A1;
int mot2_der=A2;
int trig=8;
int echo=9;
int ledalerta=7;

void setup() {
  pinMode(A3,OUTPUT);
  pinMode(A4,OUTPUT);
  pinMode(A1,OUTPUT);
  pinMode(A2,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  pinMode(7,OUTPUT);
}

void loop() {
 int pulsos,distancia;
 digitalWrite(trig,LOW);
 delayMicroseconds(3);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);

 pulsos=pulseIn(echo,HIGH);
 distancia=(pulsos/58);


 if(distancia>15)
 {
   digitalWrite(ledalerta,LOW);
   avanzar();


 }

 if(distancia<15)
 {
   digitalWrite(ledalerta,HIGH);
   parar();
   delay(600);
   retro();
   delay(1000);
   giroderecha();
   delay(1000);
   avanzar();  }


}

void avanzar(){
  analogWrite(mot1_izq,250);
  digitalWrite(mot1_der,LOW);
  analogWrite(mot2_izq,240);
  digitalWrite(mot2_der,LOW);
}

void parar(){
  analogWrite(mot1_izq,LOW);
  digitalWrite(mot1_der,LOW);
  analogWrite(mot2_izq,LOW);
  digitalWrite(mot2_der,LOW);
}

void retro(){
  analogWrite(mot1_izq,LOW);
  digitalWrite(mot1_der,240);
  analogWrite(mot2_izq,LOW);
  digitalWrite(mot2_der,201);
}

void giroderecha(){
  analogWrite(mot1_izq,LOW);
  digitalWrite(mot1_der,200);
  analogWrite(mot2_izq,200);
  digitalWrite(mot2_der,LOW);
}
