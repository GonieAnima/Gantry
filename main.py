#main executable program for the stepper motor control
import RPi.GPIO as GPIO
import time
from motion.TB6600_interface import Stepper
from motion.locatePos import posLocate

if __name__ == '__main__':
    GPIO.setmode(GPIO.BOARD)
    x_stepper = Stepper(11, 13, 200)
    y_stepper = Stepper(15, 16, 200)
    posLocate(18, 22)
    x_stepper.setSpeed(200)
    y_stepper.setSpeed(200)
    while True:
        try:
            input_str = input("Enter positions (x,y): ")
            x_pos, y_pos = map(int, input_str.split(','))
            x_stepper.move_to(x_pos)
            y_stepper.move_to(y_pos)
        except KeyboardInterrupt:
            print("Exiting")
            break

    print("Cleaning up")
    GPIO.cleanup()