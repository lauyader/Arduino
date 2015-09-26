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
 
 
int input; 

int IN1 = 12; 
int IN2 = 11;

int IN3 = 10; 
int IN4 = 9;



int led = 13;


char avanzar='w';
char izquierda='a';
char derecha='d';
char retroceder='x';
char parar='s';

 
void setup()
{
  
  Serial.begin(9600);
    // Encendido del Led
  pinMode (led, OUTPUT);
  
  pinMode (IN1, OUTPUT);    // Input4 conectada al pin 6 
  pinMode (IN2, OUTPUT);    // Input3 conectada al pin 7
  
  
  
  pinMode (IN4, OUTPUT);    // Input4 conectada al pin 4 
  pinMode (IN3, OUTPUT);    // Input3 conectada al pin 5
  
    // Entrada por el Teclado
 
  
  

  
}

void loop(){
  if(Serial.available()>0){ // Si existen datos de entrada en la comunicacion serial hacer lo siguiente 
    input=Serial.read(); // Guardamos el dato introducido 
     
      if(input==avanzar){ // Si el dato es igual a 1 
        digitalWrite(led, HIGH); // Encendemos el led 
        Serial.println("Led Avanzar") ;    
         digitalWrite (IN4, HIGH);
         digitalWrite (IN2, LOW); 
         digitalWrite (IN3, LOW); 
         digitalWrite (IN1, HIGH);
        } 
        else {

        
        }
        
      if(input==retroceder){ // Si el dato es igual a 1 
        digitalWrite(led, HIGH); // Encendemos el led 
        Serial.println("Led Retroceso") ;     
         digitalWrite (IN4, LOW);
         digitalWrite (IN3, HIGH); 
         digitalWrite (IN2, HIGH); 
         digitalWrite (IN1, LOW);
         
        }  
        
        
    /* 
    else{ // De lo contrario 
      digitalWrite(led, LOW); // Apagamos le led 
      Serial.println("Led Apagado"); 
    } */  
        if(input==izquierda){ // Si el dato es igual a 1 
        digitalWrite(led, HIGH); // Encendemos el led 
        Serial.println("Led Izquierda") ;
           digitalWrite (IN4, LOW);
          digitalWrite (IN3, LOW);     
        
        // Motor Izquierdo  se Activa
          digitalWrite (IN2, HIGH);
          digitalWrite (IN1, LOW); 
 
        
      
        
        } 
  
        if(input==derecha){ // Si el dato es igual a 1 
        digitalWrite(led, HIGH); // Encendemos el led 
        Serial.println("Led Derecha") ; 
                digitalWrite (IN2, LOW);
          digitalWrite (IN1, LOW);    
          digitalWrite (IN4, HIGH);
          digitalWrite (IN3, LOW); 
        
        
        
        } 
        
  
 
         if(input==parar){ // Si el dato es igual a 1 
        digitalWrite(led,LOW); // Encendemos el led 
        Serial.println("Led Apagado") ;  
         digitalWrite (IN4, LOW);
         digitalWrite (IN2, LOW); 
         digitalWrite (IN3, LOW); 
         digitalWrite (IN1, LOW);
        
        }          

    } 
  
  


  /*
  

  
  //  dos Motores   que gira en un sentido
  digitalWrite (IN4, HIGH);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN3, LOW); 
  digitalWrite (IN1, LOW);
  delay(4000);
  // Motor no gira
  digitalWrite (IN4, LOW);
  digitalWrite (IN2, LOW);
  delay(100);
  
  // Motor Izquierdo  se Activa
  //  digitalWrite (IN2, HIGH);
  //digitalWrite (IN1, LOW); 
  //delay(4000);
  // Motor no gira
  //digitalWrite (IN2, LOW); 
  //delay(100);
  
  
  
  
  // Enciende el led AZUL
  
    // Led Intermitente
  digitalWrite (led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
  
  
  // Motor gira en sentido inverso
  digitalWrite (IN3, HIGH);
  delay(4000);
  // Motor no gira
  digitalWrite (IN3, LOW); 
  delay(100);
  
  
 
  
  
  
  
 */ 
  
  
}
