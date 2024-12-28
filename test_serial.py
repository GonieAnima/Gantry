import serial
import time

# Configure the serial port
ser = serial.Serial('COM3', 115200, timeout=1)  # Change 'COM3' to your serial port

def send_data(xPos, yPos):
    data = f"{xPos},{yPos}\n"
    ser.write(data.encode())

if __name__ == "__main__":
    try:
        while True:
            xPos = int(input("Enter x integer: "))
            yPos = int(input("Enter y integer: "))
            send_data(xPos, yPos)
            time.sleep(1)
    except KeyboardInterrupt:
        print("Program terminated")
    finally:
        ser.close()