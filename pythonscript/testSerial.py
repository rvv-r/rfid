import serial
import time

ser = serial.Serial('COM3', baudrate = 9600, timeout=1)
time.sleep(3)

def getUID():
    ser.write(b'a')
    dataPorte1 = ser.readline().decode('ascii')
    return dataPorte1

def getSecteur1():
    ser.write(b'b')
    dataPorte2 = ser.readline().decode('ascii')
    return dataPorte2

while (1):
    userInput = input('Sélection action :')

    if userInput == 'd':
        print(getUID())
