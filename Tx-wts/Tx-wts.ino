#include "HX711.h"
#define calibration_factor 6670
#define DOUT  3
#define CLK  2
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
HX711 scale;
const byte address[6] = "00001";
void setup() {
  Serial.begin(19200);
  scale.begin(DOUT, CLK);
  scale.set_scale(calibration_factor); 
  scale.tare(); 
  radio.begin();
  radio.setPALevel(RF24_PA_MIN);
  radio.setDataRate(RF24_2MBPS);
}


void loop() {
    Serial.print("Reading: ");
    float c = scale.get_units();
    if(c < 0){
      c = c * -1;
    }
    c = c*100;
    int temp = (int)c;
    int temp2 = temp;
    int arrSize = 0;
    while(temp != 0){
      temp = temp/10;
      arrSize++;
    }
    int dataToSend[arrSize];
    int index = 0;
    while(arrSize != 0){
      dataToSend[index] = temp2%10;
      temp2/10;
      arrSize--;
    }
    
    Serial.print(c); 
    Serial.print(" lbs"); 
    Serial.println();
    radio.write(&dataToSend, sizeof(dataToSend));
}
