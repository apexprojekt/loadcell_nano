
#include "HX711.h"
#include<Wire.h>
#include <SoftwareSerial.h>
#include <SPI.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

long reading = 0;

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
}

void loop() {
if (scale.is_ready()) {
    long reading = scale.read();
    reading=reading-31750;
    reading=reading*-1;
    reading=reading/9;
    reading=reading/100;

    Serial.println(reading);


  } else {
    //Serial.println("HX711 not found.");
  }

  delay(10);
}
