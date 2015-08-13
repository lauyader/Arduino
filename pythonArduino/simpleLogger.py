# this is a very simple sample script for logging data from an Arduino
import serial # http://pyserial.sourceforge.net/


# set this to your serial port (e.g. COM4 on windows or /tty.usb...)
SERIAL_PORT = "COM12"


# log data from serial port into a text file
def logSensors():
    
    # open the serial port
    serialConnection = serial.Serial( SERIAL_PORT, timeout=2.0 )
    
    # open the output file (for appending)
    outputFile = open( "sensorLog.csv", "a" )
    
    # loop until user breaks
    while True:
        data = serialConnection.readline().strip()
        if data:
            print data
            outputFile.write( data + "\n" )
        
    
# if run as top-level script
if __name__ == "__main__":
    try:
        logSensors()
    except KeyboardInterrupt:
        pass