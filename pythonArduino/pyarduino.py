# Archivo: led_boton.py

import pyfirmata
import termios, fcntl, sys, os
fd = sys.stdin.fileno()

oldterm = termios.tcgetattr(fd)
newattr = termios.tcgetattr(fd)
newattr[3] = newattr[3] & ~termios.ICANON & ~termios.ECHO
termios.tcsetattr(fd, termios.TCSANOW, newattr)

oldflags = fcntl.fcntl(fd, fcntl.F_GETFL)
fcntl.fcntl(fd, fcntl.F_SETFL, oldflags | os.O_NONBLOCK)
placa = pyfirmata.Arduino('/dev/ttyACM0')

print('Firmata version: %d.%d' % placa.get_firmata_version())
print('pyFirmata version:', pyfirmata.__version__)


PIN = 12 # Pin 12 is used
PIN10 = 10
PIN9 = 9
DELAY = 1 # A 2 seconds delay1

# Control al presionar teclas
try:
    while 1:
        try:
            c = sys.stdin.read(1)
           # print "Got character", repr(c)


            if c == "s":
               print "Centro"
               print PIN
               placa.digital[PIN10].write(1) # Set the LED pin to 1 (HIGH)
               placa.pass_time(DELAY)
               placa.digital[PIN10].write(0) # Set the LED pin to 0 (LOW)



            elif c == "a":
               print "Izquierdo"
               placa.digital[PIN].write(1) # Set the LED pin to 1 (HIGH)
               placa.pass_time(DELAY)
               placa.digital[PIN].write(0) # Set the LED pin to 0 (LOW)
            elif c == "d":
               print "derecho"
               placa.digital[PIN9].write(1) # Set the LED pin to 1 (HIGH)
               placa.pass_time(DELAY)
               placa.digital[PIN9].write(0) # Set the LED pin to 0 (LOW)
            elif c == "w":
               print "Arriba"
               placa.digital[PIN9].write(1) # Set the LED pin to 1 (HIGH)


               placa.digital[PIN10].write(1) # Set the LED pin to 1 (HIGH)

               placa.digital[PIN].write(1) # Set the LED pin to 1 (HIGH)

            elif c == "x":
               print "Abajo"

               placa.digital[PIN].write(0) # Set the LED pin to 0 (LOW)
               placa.digital[PIN9].write(0) # Set the LED pin to 0 (LOW)
               placa.digital[PIN10].write(0) # Set the LED pin to 0 (LOW)


            elif c =="q":
               print "Hasta luego"
               sys.exit(1)


        except IOError: pass



finally:
    termios.tcsetattr(fd, termios.TCSAFLUSH, oldterm)
    fcntl.fcntl(fd, fcntl.F_SETFL, oldflags)
