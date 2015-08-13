# Lectura de datos desde un Arduino
#
# Basado en el ejemplo AnalogInOutSerial de Arduino (CC-BY-SA 3.0)
# http://arduino.cc/en/Tutorial/AnalogInOutSerial
#
# 2014 Juan Luis Cano <juanlu001@gmail.com>
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
placa.setDTR(False)
time.sleep(1)
placa.flushInput()
placa.setDTR(True)
