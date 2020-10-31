#include "HX711.h"
#include<Wire.h>
#include <SoftwareSerial.h>
#include <SPI.h>

// HX711 circuit wiring
const int LOADCELL_DOUT_PIN = 2;
const int LOADCELL_SCK_PIN = 3;

long reading = 0;
long nr;

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
    nr=reading*0.5+nr*0.5;
    Serial.println(". 0");
    Serial.print("position ");
    Serial.println(reading);
    reading=nr;

  } else {
    //Serial.println("HX711 not found.");
  }

  delay(10);
}
