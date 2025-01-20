import RPi.GPIO as GPIO
import time

class Stepper():
    def __init__(self, pul, dir,total_steps):

        self.pul = pul
        self.dir = dir
        self.total_steps = total_steps

        GPIO.setup(self.pul, GPIO.OUT)
        GPIO.setup(self.dir, GPIO.OUT)

    def setSpeed(self,rpm):
        self.speed = rpm
        steps_per_second = (self.speed * self.total_steps) / 60
        delay_per_step = 1 / steps_per_second
        self.delay_per_step = delay_per_step

    def step(self, steps):
        if steps > 0:
            dir_y = 0
        if steps < 0:
            dir_y = 1
            steps = abs(steps)
        GPIO.output(self.dir, dir_y)
        time.sleep(0.01)  # Small delay to ensure direction is set
        for x in range(steps):
            GPIO.output(self.pul, 1)
            time.sleep(self.delay_per_step/2)
            GPIO.output(self.pul, 0)
            time.sleep(self.delay_per_step/2)
        
if __name__ == '__main__':
    GPIO.setmode(GPIO.BOARD)
    motor1 = Stepper(11, 13, 200)
    motor1.setSpeed(200)
    while True:
        try:
            user = int(input("Enter number of steps: "))
            motor1.step(user)
        except KeyboardInterrupt:
            print("Exiting")
            break
        
    print("Cleaning up")
    GPIO.cleanup()