import serial
import time
import datetime

ser = serial.Serial('COM3', 9600)  # Change 'COM3' to your Arduino's serial port

days_of_week = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

while True:
    current_time = time.localtime()
    day = days_of_week[current_time.tm_wday]  # Abbreviate the day
    hours = current_time.tm_hour
    minutes = current_time.tm_min
    seconds = current_time.tm_sec

    time_string = f"{hours:02d}:{minutes:02d}:{seconds:02d}\n"
    day_string = f"{day}\n"
    
    ser.write(time_string.encode())
    ser.write(day_string.encode())
    
    time.sleep(1)