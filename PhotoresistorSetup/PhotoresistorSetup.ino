int photocellPin = 1;
float photocellReading;

void setup() {
  Serial.begin(9600);
}

void loop() {
  photocellReading = analogRead(photocellPin);
  photocellReading = photocellReading / 4;

  Serial.print("Analog reading = ");
  Serial.println(photocellReading);
  delay(1000);
}
