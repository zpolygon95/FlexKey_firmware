// Modified from Sandeep Mistry's arduino-BLEPeripheral project
// https://github.com/sandeepmistry/arduino-BLEPeripheral

/*
 * Serial Port over BLE
 * Create UART service compatible with Nordic's *nRF Toolbox* and Adafruit's *Bluefruit LE* iOS/Android apps.
 */


// Import libraries (BLEPeripheral depends on SPI)
#include <SPI.h>
#include <BLEPeripheral.h>
#include "BLESerial.h"

//custom boards may override default pin definitions with BLESerial(PIN_REQ, PIN_RDY, PIN_RST)
BLESerial bleSerial;


void setup() {
  // custom services and characteristics can be added as well
  bleSerial.setLocalName("FlexKey");

  Serial.begin(9600);
  bleSerial.begin();
}

void loop() {
  bleSerial.poll();

if (bleSerial && Serial) {
    int byte;
    while ((byte = bleSerial.read()) > 0) Serial.write((char)byte);
    while ((byte = Serial.read()) > 0) bleSerial.write((char)byte);
  }
}
