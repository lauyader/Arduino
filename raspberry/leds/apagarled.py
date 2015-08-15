import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(27, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)
GPIO.output(17, True)
GPIO.output(27, True)
GPIO.output(24, True)
