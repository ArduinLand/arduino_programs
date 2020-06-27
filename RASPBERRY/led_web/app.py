#!/usr/bin/python

from  flask import Flask, request, render_template
import RPi.GPIO as GPIO

led = 40 #Definition du port GPIO

GPIO.setmode(GPIO.BOARD)
GPIO.setup(led,GPIO.OUT)

def checking ():
	check_state = GPIO.input(led)
        if check_state == 1: # Verification de l etat au depart
                state = "LED allumee"
        else:
                state = "LED eteinte"
	return state


app = Flask(__name__)

@app.route('/',methods=['GET','POST'])
def main():
	
	if request.method == 'POST' and "on" in request.form:
		GPIO.output(led,True)

	elif "off" in request.form:
		GPIO.output(led,False)
		GPIO.cleanup

	return render_template("index.html",etat = checking())


app.run(host="192.168.1.6",port=80)
