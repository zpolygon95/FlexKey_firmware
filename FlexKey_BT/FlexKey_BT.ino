// Import libraries (BLEPeripheral depends on SPI)
#include <SPI.h>
#include <BLEPeripheral.h>

//////////////
// Hardware //
//////////////
#define LED_PIN    7 // LED on pin 7
#define LED_ACTIVE LOW // Pin 7 LED is active low
#define LED_DEFAULT LOW

#define OUT_PIN    8 // OUT on pin 8
#define OUT_ACTIVE LOW // Pin 8 OUT is active low

///////////////////////
// BLE Advertisments //
///////////////////////
const char * localName = "FlexKey";
BLEPeripheral blePeriph;
BLEService bleServ("1207");
BLECharCharacteristic ledChar("1207", BLERead | BLEWrite);

void setup()
{
  Serial.begin(115200); // Set up serial at 115200 baud

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, !LED_ACTIVE);
  pinMode(OUT_PIN, OUTPUT);
  digitalWrite(OUT_PIN, !OUT_ACTIVE);

  setupBLE();
}

void loop()
{
  blePeriph.poll();

  if (ledChar.written())
  {
    int ledState = ledChar.value();
    if (ledState) {
      digitalWrite(LED_PIN, LED_ACTIVE);
      digitalWrite(OUT_PIN, OUT_ACTIVE);
    }
    else {
      digitalWrite(LED_PIN, !LED_ACTIVE);
      digitalWrite(OUT_PIN, !OUT_ACTIVE);
    }
  }
}

void setupBLE()
{
  // Advertise name and service:
  blePeriph.setDeviceName(localName);
  blePeriph.setLocalName(localName);
  blePeriph.setAdvertisedServiceUuid(bleServ.uuid());

  // Add service
  blePeriph.addAttribute(bleServ);

  // Add characteristic
  blePeriph.addAttribute(ledChar);

  // Now that device6, service, characteristic are set up,
  // initialize BLE:
  blePeriph.begin();

  // Set led characteristic to default value:
  ledChar.setValue(!LED_ACTIVE);
}
