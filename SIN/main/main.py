from communication import GET, POST
from time import sleep

while True:
	print("Trying to fetch value")
	fetch = GET()
	print(fetch)
	sleep(1)

	input(">continue?")

	print("Trying to send value")
	send = POST("Coucou :)")
	print(send)
	sleep(1)

	input(">continue?")
