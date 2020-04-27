import RPi.GPIO as GPIO
import time

trigger_pin = 37
echo_pin = 40
pwm_gpio = 12
frequence = 50

GPIO.setmode(GPIO.BOARD)
GPIO.setup(trigger_pin,GPIO.OUT)
GPIO.setup(echo_pin,GPIO.IN)
GPIO.setup(pwm_gpio, GPIO.OUT)
pwm = GPIO.PWM(pwm_gpio, frequence)


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
        return (distance_cm)

#Set function to calculate percent from angle
def angle_to_percent (angle) :
    if angle > 180 or angle < 0 :
        return False

    start = 4
    end = 12.5
    ratio = (end - start)/180 #Calcul ratio from angle to percent

    angle_as_percent = angle * ratio

    return start + angle_as_percent

# Init at 0 degres
pwm.start(angle_to_percent(0))
time.sleep(1)

while True:
        distance = get_distance()
	#distance = float(round(distance,2))
        time.sleep(1)

        if (distance <= 130) :
            pwm.ChangeDutyCycle(angle_to_percent(180))
            time.sleep(2)
        else:
            pwm.ChangeDutyCycle(angle_to_percent(0))
            time.sleep(1)
            #pwm.stop()
            #GPIO.cleanup()

       # if KeyboardInterrupt:
        #    pwm.stop()
         #   GPIO.cleanup()


