#main executable program for the stepper motor control
import RPi.GPIO as GPIO
import time
from motion.TB6600_interface import Stepper

if __name__ == '__main__':
    

GPIO.cleanup() 