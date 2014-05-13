#!/usr/bin/env python3
import serial
port = serial.Serial(port='COM3')
	

def main():
	while True:
		prompt()


def write_string(to_write):
	port.write(to_write.encode('utf-8'))

	
def prompt():
	blink = input('Enter a string to blink: ')
	write_string(blink)
	print('Waiting for blinking to finish...')
	port.read()
	
if __name__ == '__main__':
	main()
