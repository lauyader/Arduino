import serial
arduino = serial.Serial('/dev/ttyACM0', baudrate=9600, timeout=1.0)

while True:
    line = arduino.readline()
    print(line)
