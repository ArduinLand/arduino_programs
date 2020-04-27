import RPi.GPIO as GPIO
import time
import os

relay_pin = 40

GPIO.setmode(GPIO.BOARD)
GPIO.setup(relay_pin,GPIO.OUT)
#GPIO.output(relay_pin,GPIO.HIGH)

while True:

	os.system("clear")

	#state = GPIO.input(relay_pin)

	#if state is True:
	#	etat = "ALLUMER\n\n"
	#elif state is False:
	#	etat = "ETEINT\n\n"

	print("Que voulez-vous faire ?\n\n")
	print("1- Allumer la lampe\n")
	print("2- Eteindre la lampe\n")
	print("3- Sortir\n")
	#print("ETAT DE LA LAMPE = ",etat)



	choix = input("Choix = ")
	choix = int(choix)

	if choix == 2:
		GPIO.output(relay_pin,GPIO.HIGH)
		os.system("clear")
	elif choix == 1:
		GPIO.output(relay_pin,GPIO.LOW)
		os.system("clear")
	else:
		GPIO.output(relay_pin,GPIO.HIGH)
		GPIO.cleanup()
		break
