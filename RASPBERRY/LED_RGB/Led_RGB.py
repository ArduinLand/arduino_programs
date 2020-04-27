#!/usr/bin/env python3
#-- coding: utf-8 --

import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
RED = 12
GREEN = 40
BLUE = 36

GPIO.setup(RED,GPIO.OUT)
GPIO.setup(GREEN,GPIO.OUT)
GPIO.setup(BLUE,GPIO.OUT)

pwm_GREEN = GPIO.PWM (GREEN,500) #initialisation du pwm pr led verte
pwm_RED = GPIO.PWM (RED,500)
pwm_BLUE = GPIO.PWM (BLUE,500)

pwm_GREEN.start(100)
pwm_RED.start(100)
pwm_BLUE.start(100)

duty = input ('Entrer la luminosite rouge: ')
duty = int (duty)
pwm_RED.ChangeDutyCycle(duty)

duty = input ('Entrer la luminosite verte: ')
duty = int (duty)
pwm_GREEN.ChangeDutyCycle(duty)

duty = input ('Entrer la luminosite bleu: ')
duty = int (duty)
pwm_BLUE.ChangeDutyCycle(duty)
