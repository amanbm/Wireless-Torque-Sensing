#include "HX711.h"
#define calibration_factor 1
#define DOUT  3
#define CLK  2
#include <SPI.h>
HX711 scale;



#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN



void setup() {
  Serial.begin(9600);
  scale.begin(DOUT, CLK);
  scale.set_scale(6650);
  scale.tare();
}

void loop() {
  Serial.print(scale.get_units());
  Serial.println(" in*lbs");

}
