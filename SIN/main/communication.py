import serial
import time

ser = serial.Serial('/dev/ttyUSB1', 115200, timeout=1.0)
time.sleep(1.5)
ser.reset_input_buffer()
print("Serial OK")

def GET():
	try:
		time.sleep(0.01)
		if ser.in_waiting > 0:
			line = ser.readline().decode('utf-8')
			print(f"received: '{line}'")
			return(line)
	except Exception as e:
		return(f"An error occured: {e}")

def POST(message):
	try:
		time.sleep(0.01)
		print(f"Sending: '{message}'")
		ser.write(message.encode('utf-8'))
	except Exception as e:
		return(f"An error occured: {e}")
