import RPi.GPIO as GPIO
import time

relay_pin = 40
#led_pin = 7

GPIO.setmode(GPIO.BOARD)
GPIO.setup(relay_pin, GPIO.OUT)
#GPIO.setup(led_pin, GPIO.OUT)


#GPIO.output(led_pin,True)
GPIO.output(relay_pin,True)

while True:

	GPIO.output(relay_pin,False)
	time.sleep(3)
	GPIO.output(relay_pin,True)
	time.sleep(3)
	#GPIO.cleanup()	
