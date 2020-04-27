import RPi.GPIO as GPIO
import time

trigger_pin = 37
echo_pin = 40

GPIO.setmode(GPIO.BOARD)
GPIO.setup(trigger_pin,GPIO.OUT)
GPIO.setup(echo_pin,GPIO.IN)

def send_trigger_pulse():
        GPIO.output(trigger_pin,True)
        time.sleep(0.0001)
        GPIO.output(trigger_pin,False)

def wait_for_echo(value, timeout):
        count = timeout
        while GPIO.input(echo_pin) != value and count > 0:
                count = count - 1

def get_distance():
        send_trigger_pulse()
        wait_for_echo(True, 10000)
        start = time.time()
        wait_for_echo(False, 10000)
        finish = time.time()
        pulse_len = finish - start
        distance_cm = pulse_len / 0.000058
        distance_in = distance_cm / 2.5
        return (distance_cm, distance_in)

while True:
        print("cm = %f\t inches = %f" % get_distance())
        time.sleep(1)

