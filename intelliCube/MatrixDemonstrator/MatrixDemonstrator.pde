  final int width = 8;
  final int height = 8;
  
  final int size = width * 5 / 2;
  
  final int xRes = width * 32;
  final int yRes = height * 32;

/* Declare a 3D array with values for:
  * Red (0-255)
  * Blue (0-255)
  * Green (0-255)
  * Intensity (0-255)
*/
public int[][][] disp = new int[width][height][4];
  
  // Initialize "environmental" variables
  public int temp = (int)(Math.random() * 255);// (0-255)
  public int lux = (int)(Math.random() * 255); // (0-255)
  public int humidity = (int)(Math.random() * 255); // (0-255)
  
  // Set maxes and mins to be close to the temperature at the moment
  public int minTemp = temp - 20;
  public int maxTemp = temp + 20;
  public int tempRange = 40;
  public int minHumidity = humidity - 20;
  public int maxHumidity = humidity + 20;
  public int humidityRange = 40;
  public int mod = (int)(humidity / 32);
  
  // RGB Values
  public int red;
  public int green;
  public int blue;
  public int humidLevel;


void setup() {
  size(256, 256);
  frameRate(60);
  background(0);
}

/* Method to generate the next frame to display
  * Set each color to the gradient between minTemp and maxTemp
  * Use conditional logic to find out the intensity phase
  * Use modulo function to oscillate between 0 and 255 (Divisor = temp)
  */
void generate(int[][][] disp) {
  // Generate the period for the function
  // mod = mod;
  
  // Generate the range for values
  tempRange = maxTemp - minTemp;
  humidityRange = maxHumidity - minHumidity;
  
  // Generate base rgb values
  red = ((temp - minTemp) * 256) / tempRange;
  blue = 256 - red;
  green = blue;
  humidLevel = ((humidity - minHumidity) * 8 / (humidityRange)) + 1;
  int randy;
  
  for (int i = 0; i < disp.length; i++) {
    for (int j = 0; j < disp[0].length; j++) {
      
      randy = (int)(Math.random() * 64) - 32;
      
      disp[i][j][0] = red + (randy / 4);// Red
      disp[i][j][1] = green + randy; // Green
      disp[i][j][2] = blue - randy; // Blue
      disp[i][j][3] = lux * (lux * ((i % humidLevel) + 1) * ((j % humidLevel) + 1)) / 4096; // Alpha
      
      }
    }
}

void draw() {
  // Slightly alter temp and lux to mimic real world conditions
  temp += (int)((Math.random() * 4) - 2);
  lux += (int)((Math.random() * 4) - 2);
  humidity += (int)((Math.random() * 4) - 2);
  
  // Make sure the values never pass the min or max
  temp = Math.min(temp, 255);
  temp = Math.max(temp, 0);
  lux = Math.min(lux, 255);
  lux = Math.max(lux, 0);
  humidity = Math.min(humidity, 255);
  humidity = Math.max(humidity, 0);
  
  // Check to see if max / min has been passed
  minTemp = Math.min(minTemp, temp);
  maxTemp = Math.max(maxTemp, temp);
  minHumidity = Math.min(minHumidity, humidity);
  maxHumidity = Math.max(maxHumidity, humidity);
  
  System.out.print(minTemp + "\t" + temp + "\t" + maxTemp + "\n");
  //System.out.print(disp[0][0][0] + "\t" + disp[0][0][1] + "\t" + disp[0][0][2] + "\n");
  //System.out.println(frameRate);
  //System.out.println();
  
  // Generate the next pattern
  generate(disp);
  
  for (int i = 0; i < disp.length; i++) {
    for (int j = 0; j < disp[0].length; j++) {
      // Set the fill to the specific color (RGBA format)
      fill(disp[i][j][0], disp[i][j][1], disp[i][j][2], disp[i][j][3]);
      
      // Render the circle on the screen
      int x = (i * 32) + (width * 2);
      int y = (j * 32) + (width * 2);
      ellipse(x, y, size, size);
      
      }
    }
}