import serial

arduinoPort = serial.Serial('/dev/ttyACM0', 9600, timeout=1)

print "Introduce valor"
datoParaEnviar = raw_input()

while datoParaEnviar != 'salir':

      arduinoPort.write(datoParaEnviar)
      datoParaEnviar = raw_input()
