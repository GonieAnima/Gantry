import RPi.GPIO as GPIO
from motion.TB6600_interface import Stepper

def posLocate (endX, endY):         # endX and endY are the GPIO pins for the endstops
    GPIO.setup(endX,GPIO.IN)
    GPIO.setup(endY,GPIO.IN)
    x_stepper.setSpeed(30)
    y_stepper.setSpeed(30)
    if GPIO.input(endX) == 0:
        x_stepper.step(-1)
    if GPIO.input(endY) == 0:
        y_stepper.step(-1)

if __name__ == '__main__':
    while True:
        try:
            GPIO.setmode(GPIO.BOARD)
            x_stepper = Stepper(11, 13, 200)
            y_stepper = Stepper(15, 16, 200)
            posLocate()
        except KeyboardInterrupt:
            print("Exiting")
            break
        
    print("Cleaning up")
    GPIO.cleanup()