#!/usr/bin/env python3
from serial import Serial
import sys


def main():
	serial_port = find_port()
	while True:
		prompt(serial_port)


def find_port():
	locations=[
		'/dev/ttyACM0', '/dev/ttyACM1','/dev/ttyACM2',
		'/dev/ttyACM3','/dev/ttyACM4',
		'/dev/ttyACM5','/dev/ttyUSB0','/dev/ttyUSB1','/dev/ttyUSB2','/dev/ttyUSB3',
		'/dev/ttyUSB4', '/dev/ttyUSB5', '/dev/ttyUSB6', '/dev/ttyUSB7',
		'/dev/ttyUSB8', '/dev/ttyUSB9', '/dev/ttyUSB10','/dev/ttyS0',
		'/dev/ttyS1', '/dev/ttyS2', 'com2', 'com3', 'com4', 'com5', 'com6',
		'com7', 'com8', 'com9', 'com10', 'com11', 'com12', 'com13', 'com14',
		'com15', 'com16', 'com17', 'com18', 'com19', 'com20', 'com21', 'com1',
		'end'
	]

	for device in locations:
		try:
			serial_port = Serial(device)
			return serial_port
		except:
			if device == 'end':
				print('Unable to find Serial Port.')
				sys.exit()


def write_string(to_write, port):
	port.write(to_write.encode('utf-8'))

	
def prompt(port):
	blink = input('Enter a string to blink: ')
	if blink == '':
		sys.exit(0)
	write_string(blink, port)
	print('Waiting for blinking to finish...')
	port.read()
	
if __name__ == '__main__':
	main()
