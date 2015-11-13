int sensorPin = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
   int reading = analogRead(sensorPin);
   
   float voltage = reading * 5.0;
   voltage = voltage/1024;
   
   Serial.print(voltage);
   Serial.println(" volts");

   float temperatureC = (voltage - 0.5) * 100;

   Serial.print(temperatureC);
   Serial.println(" degrees C");

   float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;

   Serial.print(temperatureF);
   Serial.println(" degrees F");

   delay(1000);
}

public 
