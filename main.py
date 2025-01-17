#main executable program for the stepper motor control
import RPi.GPIO as GPIO
import time
from motion.TB6600_interface import Stepper
from motion.locatePos import posLocate

if __name__ == '__main__':
    x_stepper = Stepper(11, 13, 200)

GPIO.cleanup()