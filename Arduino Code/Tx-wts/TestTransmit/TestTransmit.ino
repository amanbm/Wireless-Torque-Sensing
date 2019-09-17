#include "HX711.h"
#define calibration_factor 2173
#define DOUT  3
#define CLK  2
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
int data = 0;
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  radio.write(&data, sizeof(data));
  data = data + 1;
  delay(750);
}
