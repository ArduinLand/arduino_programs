"""
Ce programme va nous permettre de contrôler la LED
RGB à l'aide d'une interface graphique.

23/09/19

"""

#!/usr/bin/env python3
#-- coding: utf-8 --



import RPi.GPIO as GPIO
import tkinter

GPIO.setmode (GPIO.BOARD)

RED = 12
GREEN = 40
BLUE = 36

GPIO.setup(RED,GPIO.OUT) #Configuration du port GPIO (12)
GPIO.setup(GREEN,GPIO.OUT)
GPIO.setup(BLUE,GPIO.OUT)

pwmRED = GPIO.PWM (RED,500)
pwmGREEN = GPIO.PWM (GREEN,500)
pwmBLUE = GPIO.PWM (BLUE,500)

pwmBLUE.start (100)
pwmGREEN.start (100)
pwmRED.start (100)

class App :

    def __init__(self, master):

        frame = Frame(master)
        frame.pack()
        Label(frame, text=' RED ').grid(row = 0 , column = 0)
        Label(frame, text=' GREEN ').grid(row = 1 , column = 0)
        Label(frame, text=' BLUE ').grid(row = 2 , column = 0)

        scaleRed = Scale(frame, from= 0, to= 100, orient= HORIZONTAL, command= self.updateRed)
        scaleRed.grid(row = 0 , column = 1)

        scaleGreen = Scale(frame, from= 0, to= 100, orient= HORIZONTAL, command= self.updateGreen)
        scaleGreen.grid (row= 1, column= 1)

        scaleBlue = Scale(frame, from= 0, to = 100, orient = HORIZONTAL, command = self.updateBlue)
        scaleBlue.grid(row=2, column=1)

    def updateRed (self,duty)
        pwmRED.ChangeDutyCycle(duty)

    def updateGreen (self,duty)
        pwmGREEN.ChangeDutyCycle(duty)

    def updateBlue (self,duty)
        pwmBLUE.ChangeDutyCycle(duty)

    root = Tk()
    root.wm_title('RGB LED CONTROL')
    app = App(root)
    root.geometry("200x150+0+0")
    root.mainloop()