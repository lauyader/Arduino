// Las anteriores versiones, el sensor por el Serialprintln , cuando se mantenia a distancias superiores a la que es 
// capaz de reconocer y se mantenia en esa posición, Se neutralizaba, manteniendose en 0.
// Este código corrigio la falla. Agradecido a http://www.educachip.com/hc-sr04-arduino-tutorial/

/*Pines a utilizar por Arduino. Puedes modificarlos por los pines digitales que desees*/

int Trig=4;
int Echo=3;

//Variable en la que se va a almacenar el valor correspondiente a la distancia
int Dist;

void setup() {
Serial.begin(9600);
pinMode (Trig, OUTPUT);
pinMode (Echo, INPUT);

}

//Este módulo calcula y devuelve la distancia en cm.
/*
Puedes poner el código del módulo directamente en el loop o utilizar el módulo
para reducir el número de líneas de código del loop o reutilizar el código
*/
void ultrasonido (int &Distancia){

//Para estabilizar el valor del pin Trig se establece a LOW
digitalWrite (Trig, LOW);
delay(10);

//Se lanzan los 8 pulsos
digitalWrite (Trig, HIGH);
delay(10);
digitalWrite (Trig, LOW);

/*
Se mide el tiempo que tarda la señal en regresar y se calcula la distancia.

Observa que al realizar pulseIn el valor que se obtiene es tiempo, no distancia

Se está reutilizando la variable Distancia.
*/

Distancia= pulseIn (Echo, HIGH);
Distancia=Distancia/58;
Serial.println(Distancia);
Serial.println("Hola Mundo");
delay(100);
  
}

void loop() {

ultrasonido (Dist);

delay (250);
}
