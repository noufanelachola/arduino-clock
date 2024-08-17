# Arduino and Python Clock Project

This project displays the current time and day of the week on an I2C LCD connected to an Arduino, with the time being sent from a Python script.

## Installation

### Python Dependencies
1. Ensure you have Python 3 installed.
2. Install the required Python packages by running:
pip install -r python/requirements.txt


### Arduino Libraries
1. Install the following libraries using the Arduino IDE's Library Manager:
- LiquidCrystal_I2C
- Wire

## Usage

### Arduino
1. Open the `clock.ino` file in the Arduino IDE.
2. Upload the code to your Arduino board.

### Python
1. Run the Python script to send the current time and day to the Arduino:
`python clockp.py`.
2. Also dont forget to edit the COM port.

## License
[Your chosen license]