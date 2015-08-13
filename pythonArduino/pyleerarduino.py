#!/usr/bin/python

# Importamos la libreira de PySerial
import serial

# Abrimos el puerto del arduino a 9600
arduino = serial.Serial('/dev/ttyACM0', baudrate=9600, timeout=1.0)
# Creamos un buble sin fin
#while True:
  # leemos hasta que encontarmos el final de linea
 # sArduino = PuertoSerie.readline()
  # Mostramos el valor leido y eliminamos el salto de linea del final
  #print "Valor Arduino: " + sArduino.rstrip('\n')
