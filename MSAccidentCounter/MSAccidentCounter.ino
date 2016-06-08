#include <TimeLib.h>
#include <LiquidCrystal.h>

#define TIME_HEADER  "T"   // Header tag for serial time sync message
#define TIME_REQUEST  7    // ASCII bell character requests a time sync message 

/* Initialize pins for LCD */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buttonPin = 10;
int buttonState = 0;

int waitAmount = 1000;

void setup() {
  /* Initialize LCD */
  lcd.begin(16, 2);

  /* Initialize button */
  pinMode(buttonPin, INPUT);

  /* Initialize timer */
  setTime(0);

  Serial.begin(9600);
}

void loop() {
  /* Clear the LCD */
  lcd.clear();
  
  /* Check to see if the button has been pressed */
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
      setTime(0); // Reset the timer to zero
  }

  /* Call the print time method to determine the time and print it */
  printTime();

  Serial.println(now());

  delay(waitAmount);
  
}

String isPlural(int num) {
  /* Returns an s if the time unit is plural (e.g. more than 1) */
  if (num != 1) {
    return "s";
  }
  else return "";
}

void preAmble() {
  lcd.begin(16, 2);
  lcd.print("Accident free");
  lcd.setCursor(0, 1);
  lcd.print("for ");
}

void printTime() {

  /* Print the preamble */
  preAmble();
  
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

