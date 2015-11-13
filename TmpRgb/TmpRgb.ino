int sensorPin = 0;
int interval = 1000;

void setup() {
  Serial.begin(9600);

  int redPin = 9;
  int bluePin = 10;
  int greenPin = 11;
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int reading = analogRead(sensorPin);
  int intensity = (reading - 140) * 16;

  int blue = 255 - intensity;
  int red = intensity;

  float temperatureC = (voltage - 0.5) * 100;

  analogWrite(redPin, red);
  analogWrite(bluePin, blue);

  Serial.print(temperatureC);
  Serial.println(" degrees F");

  delay(interval);
}
