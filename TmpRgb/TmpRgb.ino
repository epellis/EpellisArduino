int sensorPin = 0;
int interval = 400;

int redPin = 9;
int bluePin = 11;
int greenPin = 10;

void setup() {
  Serial.begin(9600);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  int reading = analogRead(sensorPin);
  int intensity = (reading - 140) * 18;

  Serial.println(intensity);

  int blue = 255 - intensity;
  int red = intensity;

  float voltage = (reading * 5.0)/1024;
  float temperatureC = (voltage - 0.5) * 100;

  analogWrite(redPin, red);
  analogWrite(bluePin, blue);

  Serial.print(temperatureC);
  Serial.println(" degrees C");

  delay(interval);
}
