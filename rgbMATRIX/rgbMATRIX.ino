#include <Colorduino.h>

void setup() {
  Colorduino.Init();

  unsigned char whiteBalVal[3] = {36, 63, 53};

  Colorduino.SetWhiteBal(whiteBalVal);
}

void loop() {
  Colorduino.ColorFill(0, 255, 255);
}
