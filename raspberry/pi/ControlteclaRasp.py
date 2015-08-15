#!/usr/bin/env python
#-*- coding: UTF-8 -*-

import termios, fcntl, sys, os
import RPi.GPIO as GPIO # Cargamos la libreria RPi.GPIO  

from time import sleep  # cargamos la función sleep del módulo time 
fd = sys.stdin.fileno()  

oldterm = termios.tcgetattr(fd)
newattr = termios.tcgetattr(fd)
newattr[3] = newattr[3] & ~termios.ICANON & ~termios.ECHO
termios.tcsetattr(fd, termios.TCSANOW, newattr)

oldflags = fcntl.fcntl(fd, fcntl.F_GETFL)
fcntl.fcntl(fd, fcntl.F_SETFL, oldflags | os.O_NONBLOCK)



GPIO.setmode(GPIO.BCM)  # Ponemos la Raspberry en modo BCM  

GPIO.setwarnings(False)  
GPIO.setup(25, GPIO.OUT)  # Ponemos el pin GPIO nº25 como salida para el LED #1  
GPIO.setup(24, GPIO.OUT)  # Ponemos el pin GPIO nº24 como salida para el LED #2  
  
white = GPIO.PWM(25, 100)   # Creamos el objeto 'white' en el pin 25 a 100 Hz  
red = GPIO.PWM(24, 100)     # Creamos el objeto 'red' en el pin 24 a 100 Hz 
  
white.start(0)              # Iniciamos el objeto 'white' al 0% del ciclo de trabajo (completamente apagado)  
red.start(0)              # Iniciamos el objeto 'red' al 100% del ciclo de trabajo (completamente encendido) 

i = 0      #numero de intensidad del led

try:
  
   while 1:
        try:
            
            c = sys.stdin.read(1)
           # print "Got character", repr(c)
            
           
            if (c == "s"):
               print "Centro"
               white.ChangeDutyCycle(0)  
               i = 0
            elif c == "a":
               print "Izquierdo"
            elif c == "d":
               print "derecho"
            elif c == "w":
               print "Arriba"
               if (i < 100):
               	white.ChangeDutyCycle(i)      # LED 
               	i = i + 10
               if (i >= 150):
                white.ChangeDutyCycle(0)
                i = 0
 	       print (i)

            elif c == "x":
               print "Abajo"
              
               if (i < 100):
                white.ChangeDutyCycle(i)      # LED
                i =  i + 1
               if (i >= 100):
                white.ChangeDutyCycle(0)
                i = 0

               print i  



            elif c =="q":
               print "Hasta luego"
               sys.exit(1)


        except IOError: pass
	 
  
	 
finally:
    termios.tcsetattr(fd, termios.TCSAFLUSH, oldterm)
    fcntl.fcntl(fd, fcntl.F_SETFL, oldflags)

