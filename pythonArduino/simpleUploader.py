# this is a very simple sample script for sending data from an Arduino to the Xively service
import xively
import datetime
import serial # http://pyserial.sourceforge.net/


# edit this to match your device
API_KEY = 'abc'
FEED_ID = '123'
DATA_STREAM = 'Temperature'


# set this to your serial port (e.g. COM4 on windows or /tty.usb...)
SERIAL_PORT = "COM12"


# use this to control the number of seconds between updates
UPDATE_INTERVAL_SECONDS = 15


# send arduino data to Xively
def sendDataToXively():

    # open connection to Xively
    api = xively.XivelyAPIClient( API_KEY )
    feed = api.feeds.get( FEED_ID )
    datastream = feed.datastreams.get( DATA_STREAM )

    # open the serial port
    serialConnection = serial.Serial( SERIAL_PORT, timeout=2.0 )

    # the last time we sent to the stream
    lastSend = None
    
    # loop until user interrupts
    while True:
    
        # get data
        data = serialConnection.readline().strip()
        if data:
            print data
            values = [float( v ) for v in data.split( "," )]
            value = values[ 0 ]

            # send to xively
            now = datetime.datetime.utcnow()
            if lastSend is None or now - lastSend > datetime.timedelta( seconds = UPDATE_INTERVAL_SECONDS ):
                print "sent %.2f at %s" % (value, now.strftime( "%Y-%m-%d %H:%M:%S" ))
                datastream.current_value = value
                datastream.at = now
                datastream.update()
                lastSend = now


# if run as top-level script
if __name__ == "__main__":
    try:
        sendDataToXively()
    except KeyboardInterrupt:
        pass
