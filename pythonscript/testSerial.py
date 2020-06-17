import serial
import time

ser = serial.Serial('COM3', baudrate = 9600, timeout=1)
time.sleep(3)

def getDump():
    ser.write(b'd')
    arduinoData = ser.readline().decode('ascii')
    return arduinoData

while (1):
    userInput = input('Sélection action')

    if userInput == 'd':
        print(getDump())
