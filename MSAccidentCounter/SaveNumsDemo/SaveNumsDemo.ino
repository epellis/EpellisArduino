#include <EEPROM.h>

/* Generate a set of 10 integers and then store them in EEPROM for retrival */
void setup() {
  
  Serial.begin(9600);
  int address = 0;
  int nums [10];

  for (int i = 0; i < 10; i++) {
    nums[i] = rand();
  }

  for (int i = 0; i < 10; i++) {
    
    Serial.print(nums[i]);
    Serial.print("\n");
    
  }

  Serial.println();

  for (int i = 0; i < 10; i++) {
        
    unsigned char bytes[4];
    unsigned long num = nums[i];

    bytes[0] = (num >> 8) & 0xFF;
    bytes[1] = num & 0xFF;

    EEPROM.write(address, bytes[0]);
    address++;
    EEPROM.write(address, bytes[1]);
    address++;

    Serial.print(nums[i]);
    Serial.print(":\t\t");
    Serial.print((unsigned char)bytes[0]);
    Serial.print("\t");
    Serial.print((unsigned char)bytes[1]);
    Serial.println();
    
  }

  Serial.println();

  for (int i = 0; i < 10; i++) {
    int readAddress = 2 * i;

    Serial.print((unsigned char)EEPROM.read(readAddress));
    Serial.print("\t");
    Serial.print((unsigned char)EEPROM.read(readAddress + 1));
    Serial.println();

    int num;

    num = EEPROM.read(readAddress) * 256;
    num += EEPROM.read(readAddress + 1);

    Serial.print(num);
    Serial.println();
  }

}

void loop() {
}
