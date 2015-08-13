import serial #cargamos la libreria serial
import termios, fcntl, sys, os
fd = sys.stdin.fileno()

oldterm = termios.tcgetattr(fd)
newattr = termios.tcgetattr(fd)
newattr[3] = newattr[3] & ~termios.ICANON & ~termios.ECHO
termios.tcsetattr(fd, termios.TCSANOW, newattr)

oldflags = fcntl.fcntl(fd, fcntl.F_GETFL)
fcntl.fcntl(fd, fcntl.F_SETFL, oldflags | os.O_NONBLOCK)


ser = serial.Serial('/dev/ttyACM0', 9600) #inicializamos el puerto de serie a 9600 baud

#variable para almacenar el mensaje
#le asignamos un valor introducido por el usuario
print "Introduce un caracter ('s' para salir): "
entrada = raw_input()

while entrada != 's': #introduciendo 's' salimos del bucle

   ser.write(entrada) #envia la entrada por serial
   print "He enviado: ", entrada
   print "Introduce un caracter ('s' para salir): "

   entrada = raw_input() #introduce otro caracter por teclado
