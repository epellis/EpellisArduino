void setup() {
  int redPin = 9;
  int bluePin = 10;
  int greenPin = 11;
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

  int interval = 100;
  int redAdditive = 20;
  int blueAdditive = 30;
  int greenAdditive = 40;

  int red = 1;
  int blue = 1;
  int green = 1;

void loop() {
  int redPin = 9;
  int bluePin = 10;
  int greenPin = 11;
  
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);

  if (red == 0 || red == 255){
    redAdditive = redAdditive * -1;
  }
  else {
    red = red + redAdditive;
  }


  if (blue == 0 || blue == 255){
    blueAdditive = blueAdditive * -1;
  }
  else {
    blue = blue + blueAdditive;
  }


  if (green == 0 || green == 255){
    greenAdditive = greenAdditive * -1;
  }
  else {
    green = green + greenAdditive;
  }

  delay(interval);
}
