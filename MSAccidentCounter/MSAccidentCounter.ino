#include <TimeLib.h>
#include <LiquidCrystal.h>

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 10;
int buttonState = 0;

int waitAmount = 1000;

void setup() {
  lcd.begin(16, 2);

  pinMode(buttonPin, INPUT);

  Serial.begin(9600);

  int memAddress = 0;
  int timeType = 0; // Indexes through types of time, e.g. seconds is 0, minutes is 1, etc...

  setTime(
}

void loop() {
//  /* Clear the LCD */
//  lcd.clear();
//  
//  /* Check to see if the button has been pressed */
//  buttonState = digitalRead(buttonPin);
//  if (buttonState == HIGH) {
//      setTime(0); // Reset the timer to zero
//  }
//
//  /* Call the print time method to determine the time and print it */
//  printTime();
//
//  Serial.println(now());
//
//  delay(waitAmount);
//  

}

/* Returns an int from a specified address in EEPROM */
int getInt() {
  int readAddress = 0;
  
  int num;
  num = EEPROM.read(readAddress) * 256;
  num += EEPROM.read(readAddress + 1);
}

String isPlural(int num) {
  /* Returns an s if the time unit is plural (e.g. more than 1) */
  if (num != 1) {
    return "s";
  }
  else return "";
}

/* Method to print essential information */
void preAmble() {
  lcd.begin(16, 2);
  lcd.print("Accident free");
  lcd.setCursor(0, 1);
  lcd.print("for ");
}

void printTime() {

//  preAmble();
  
  /* Find out which time unit is most appropriate */
  if (month() > 1) {
    waitAmount = 31 * 24 * 3600 * 1000;
    lcd.print(month());
    lcd.print(" month" + isPlural(month()));
  } else if (day() > 1) {
    waitAmount = 24 * 3600 * 1000;
    lcd.print(day());
    lcd.print(" day" + isPlural(day()));
    waitAmount = 
  } else if (hour() > 0) {
    waitAmount = 3600 * 1000;
    lcd.print(hour());
    lcd.print(" hour" + isPlural(hour()));
  } else if (minute() > 1) {
    waitAmount = 60 * 1000;
    lcd.print(minute());
    lcd.print(" minute" + isPlural(minute()));
  } else {
    lcd.print(second());
    lcd.print(" second" + isPlural(second()));
  }
  
}
