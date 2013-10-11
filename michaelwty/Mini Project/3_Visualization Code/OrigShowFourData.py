import sys, serial
import numpy as np
from time import sleep
from collections import deque
from matplotlib import pyplot as plt
 
# class that holds analog data for N samples
class AnalogData:
  # constr
  def __init__(self, maxLen):
    self.ax = deque([0.0]*maxLen)
    self.ay = deque([0.0]*maxLen)
    self.ad = deque([0.0]*maxLen)
    self.ae = deque([0.0]*maxLen)
    self.maxLen = maxLen
 
  # ring buffer
  def addToBuf(self, buf, val):
    if len(buf) < self.maxLen:
      buf.append(val)
    else:
      buf.pop()
      buf.appendleft(val)
 
  # add data
  def add(self, data):
    assert(len(data) == 4)
    self.addToBuf(self.ax, data[0])
    self.addToBuf(self.ay, data[1])
    self.addToBuf(self.ad, data[2])
    self.addToBuf(self.ae, data[3])
    
# plot class
class AnalogPlot:
  # constr
  def __init__(self, analogData):
    # set plot to animated
    plt.ion() 
    self.axline, = plt.plot(analogData.ax)
    self.ayline, = plt.plot(analogData.ay)
    self.adline, = plt.plot(analogData.ad)
    self.aeline, = plt.plot(analogData.ae)
    plt.ylim([0, 1023])
 
  # update plot
  def update(self, analogData):
    self.axline.set_ydata(analogData.ax)
    self.ayline.set_ydata(analogData.ay)
    self.adline.set_ydata(analogData.ad)
    self.aeline.set_ydata(analogData.ae)
    plt.draw()
 
# main() function
def main():
  strPort = 'COM3'
  
  # plot parameters
  analogData = AnalogData(100)
  analogPlot = AnalogPlot(analogData)
 
  print 'plotting data...'
 

  ser = serial.Serial(strPort, 9600)
 
  while True:
     try:

       line = ser.readline()
      
       #ser = [(x,y) for x,y in zip(ser1,ser2)]
       data = [float(val) for val in line.split()] #data is a list
       if(len(data) == 4):
         analogData.add(data)
         analogPlot.update(analogData)   
     except KeyboardInterrupt:
       print 'exiting'
       break
  # close serial
  ser.flush()
  ser.close()
 
# call main
if __name__ == '__main__':
  main()
