#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F, 16, 2);  // Set the LCD address to 0x27 for a 16x2 display
String prevDay ="0";
void setup() {
    Serial.begin(9600);  // Start serial communication
    while (!Serial);     // Wait for serial connection to be established

    lcd.init();          // Initialize the LCD
    lcd.backlight();     // Turn on the backlight
    lcd.clear();    
}

void loop() {
    if (Serial.available()) {
        String receivedTime = Serial.readStringUntil('\n');
        String receivedDay = Serial.readStringUntil('\n');
        // lcd.clear();       // Clear the LCD
        lcd.setCursor(0, 0);
        lcd.print(centerAlign(receivedTime, 16));  // Center-align time
        if(prevDay != receivedDay){
          lcd.setCursor(0, 1);
          lcd.print(centerAlign(receivedDay, 16));
        } 
        prevDay = receivedDay;  // Center-align day
    }
}

String centerAlign(String text, int width) {
    int padding = max(0, (width - text.length()) / 2);
    String spaces = "";
    for (int i = 0; i < padding; i++) {
        spaces += " ";
    }
    return spaces + text;
}