# Tapaus 3, Vastaanottoyksikko, Raspberry Pi lahdekoodi

import serial
import os
import time

# creating a file where to save ldr values
f = open("savedvalues.txt", "w")

# initializing serial connection
ser = serial.Serial('/dev/ttyS0', 9600)

# amount of ldr values to be saved in a file
i = 0

# reading, decoding and saving ldr values
while i < 10:
  i += 1
  saveValue = ser.readline()
  print(saveValue)
  decodedValue = saveValue.decode("utf-8")
  f.write(decodedValue)
  time.sleep(1)

# closing file and serial connection
f.close()
ser.close()