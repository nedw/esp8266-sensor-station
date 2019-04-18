#include "ble.h"
#include "webthing.h"

BLEServer *server = NULL;
BLEService *service = NULL;
BLECharacteristic *read_characteristic = NULL;
BLECharacteristic *write_characteristic = NULL;

void WriteCallback::onWrite(BLECharacteristic* pCharacteristic)
{
  std::string s = pCharacteristic->getValue();
  const int n = atoi(s.c_str());
  if (n >= 0 && n <= 255) {
    Serial.printf("Setting brightness to %d\n", n);
    set_oled_brightness(n);
  }
}

void init_ble()
{
  Serial.println("Initialising BLE");

  BLEDevice::init("ESP32 sensor");
  server = BLEDevice::createServer();
  service = server->createService(SERVICE_UUID);

  read_characteristic = service->createCharacteristic(READ_CHARACTERSTIC_UUID, BLECharacteristic::PROPERTY_READ);
  write_characteristic = service->createCharacteristic(WRITE_CHARACTERSTIC_UUID, BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_READ);
  write_characteristic->setCallbacks(new WriteCallback);

  service->start();
  server->getAdvertising()->start();
  Serial.println("BLE initialised");
}

void set_ble(const char *s)
{
    read_characteristic->setValue(s);
}
