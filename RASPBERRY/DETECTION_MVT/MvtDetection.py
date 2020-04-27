"""
Capteur de mouvement 
30/09/19
"""
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(40,GPIO.IN)
i = 0

while True:
	try:
		state = GPIO.input(40)
		if state == True :
			print('mouvement ',i,' detecte')
			i = i + 1
			time.sleep(1)

	except KeyboardInterrupt: # on sort par un Ctrl+C
    		print("&amp;amp;amp;quot;Terminé!&amp;amp;amp;quot;")
    		# réinitialisation des ports GPIO pour sortir proprement
    		GPIO.cleanup()
