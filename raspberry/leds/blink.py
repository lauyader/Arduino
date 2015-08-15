#EJEMPLO DE BLINKING CON RASPBERRY PI
#Escrito por Gl4r3
import RPi.GPIO as GPIO #importamos la libreria y cambiamos su nombre por "GPIO"
import time #necesario para los delays
import sys
#establecemos el sistema de numeracion que queramos, en mi caso BCM
GPIO.setmode(GPIO.BCM)
 
#configuramos el pin GPIO17 como una salida
GPIO.setup(17, GPIO.OUT)
GPIO.setup(27, GPIO.OUT) 
#encendemos y apagamos el led 5 vec

   
#for i in range(0,1):
x='si'
while x=='si':
 tecla = sys.stdin.read(1)
 if tecla == 'w':  
#    GPIO.output((17, GPIO.LOW)
#    time.sleep(1)
#    GPIO.output(27, GPIO.LOW)
#    time.sleep(1)
     GPIO.output(27, GPIO.HIGH)
     time.sleep(1)
     GPIO.output(17, GPIO.HIGH)
     time.sleep(1)
 else:
    x='no'
    print 'se sale del ciclo'


 if tecla == 'a':
    GPIO.output(17, GPIO.HIGH)
    time.sleep(1)
    GPIO.output(27, GPIO.HIGH)
    time.sleep(1)
#    GPIO.output(27, GPIO.HIGH)
#    time.sleep(1)
#    GPIO.output(17, GPIO.LOW)
#    time.sleep(1)
 else:
    x='no'
    print 'se sale del ciclo'

GPIO.cleanup()  #devuelve los pines a su estado inicial
