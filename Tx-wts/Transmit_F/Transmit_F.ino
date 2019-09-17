#include "HX711.h"
#define calibration_factor 1
#define DOUT  3
#define CLK  2
#include <SPI.h>
HX711 scale;
const byte address[] = "00001";

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN



void setup() {
  Serial.begin(9600);
  scale.begin(DOUT, CLK);
  scale.set_scale(6650);
  scale.tare();
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  float scaleValue = scale.get_units();
  Serial.print(scaleValue);
  Serial.println(" in*lbs");
  radio.write(&scaleValue, sizeof(scaleValue));
}
