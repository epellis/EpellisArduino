#include <Colorduino.h>

 int b = 0;
 int g = 255;
 int polarity = 1;

void setup() {
  Colorduino.Init();

  unsigned char whiteBalVal[3] = {36, 63, 53};

  Colorduino.SetWhiteBal(whiteBalVal);
}

void loop() {
  if (b < 0 || b > 255) {
    polarity = polarity * -1;
  }

  b += polarity;
  g = 255 - b;

  Colorduino.ColorFill(0, g, b);
  
  delay(100);
}
