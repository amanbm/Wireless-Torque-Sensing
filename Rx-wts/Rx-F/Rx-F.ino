#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening();

}

void loop() {
  float data;
  if(radio.available()){
    radio.read(&data, sizeof(data));
    Serial.println(data);
  }
  
}
