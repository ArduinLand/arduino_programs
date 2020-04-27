#!/usr/bin/env python

import RPi.GPIO as GPIO

import time

 

RelayPin = 40    # pin17

 

def setup():

      GPIO.setmode(GPIO.BOARD)     

      GPIO.setup(RelayPin, GPIO.OUT)

      GPIO.output(RelayPin, GPIO.HIGH)

 

def loop():

      while True:

            print '...relay on'

            GPIO.output(RelayPin, GPIO.LOW)

            time.sleep(2)

            print 'relay off...'

            GPIO.output(RelayPin, GPIO.HIGH)

            time.sleep(2)

 

def destroy():

      GPIO.output(RelayPin, GPIO.HIGH)

      GPIO.cleanup()                    

 

if __name__ == '__main__':     # Program start from here

      setup()

      try:

            loop()

      except KeyboardInterrupt:  # Arret 'Ctrl+C'

            destroy()

