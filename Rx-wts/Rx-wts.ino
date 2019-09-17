
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(19200);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    int text[100];
    radio.read(&text, sizeof(text));
    for(int i = 0; i < 2; i++){
      Serial.print(text[i]);
    }
    Serial.println();
  } else {
    Serial.println("");
    delay(750);
  }
}
