// Declare what analog pins are recieving input
int sensorPin = 0;
int photocellPin = 1;

// Declare the refresh rate of the program
int interval = 500;

// Declare what digital pins are outputting rgb values
int redPin = 9;
int bluePin = 11;
int greenPin = 10;

// Decalre the base values of the sensors
float baseTemp;
float baseLight;

// Declare the number of tests done to get the base temperature and base light level
int sampleTime = 100;

void setup() {

  // Broadcast information through serial for debugging
  Serial.begin(9600);

  // Declare that the aformentioned pins are being used as output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Run a sample to calculate an average temperature and average light level
  for (int i = 0; i < sampleTime; i++) {
    baseTemp += analogRead(sensorPin);
    baseLight += analogRead(photocellPin);
  }

  // Calculate the average by dividing the sum by the amount of samples
  baseTemp = baseTemp / sampleTime;
  baseLight = baseLight / sampleTime;

  // Print the base values to serial to debug
  Serial.println(baseTemp);
  Serial.println(baseLight);
  
}

void loop() {

  // Read and store values from sensor inputs
  int reading = analogRead(sensorPin);
  int photocellReading = analogRead(photocellPin);
  
  // Convert data into usable integers for output on a 0 - 255 scale
  int intensity = (reading - 140) * 18;

  // Set red, green, and blue values to output to an rgb
  int green = (photocellReading - 960) * 4;
  int blue = 255 - intensity;
  int red = intensity;

  // Write rgb values to the light
  analogWrite(redPin, red);
  analogWrite(bluePin, blue);
  analogWrite(greenPin, green);
  
  // Read voltage of temperature module and convert it into degrees Celcius
  float voltage = (reading * 5.0)/1024;
  float temperatureC = (voltage - 0.5) * 100;

  // Print out data for debugging
  Serial.print("degrees C = ");
  Serial.println(temperatureC);
  Serial.print("Green = ");
  Serial.println(green);
  Serial.print("Intensity level = ");
  Serial.println(intensity);
  Serial.println(" ");

  // Delay the program based on the already entered refresh ratio
  delay(interval);
}
