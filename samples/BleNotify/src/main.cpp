#include <freertos/FreeRTOS.h>   // Include the base FreeRTOS definitions
#include <freertos/task.h>       // Include the task definitions
#include "sdkconfig.h"
#include "..\..\..\src\BLEDevice.h"
#include "..\..\..\src\BLEServer.h"
#include "..\..\..\src\BLEUtils.h"
#include "..\..\..\src\BLE2902.h"

BLEServer* _server = NULL;
BLECharacteristic* _characteristic = NULL;
bool _deviceConnected = false;
bool _oldDeviceConnected = false;
uint32_t _value = 0;

void Delay(uint32_t ms);

#define SERVICE_UUID        "94046761-ff6d-4773-b9b6-abccfbb0b282"
#define CHARACTERISTIC_UUID "4c20ade9-d75d-414b-965c-0276769a85ea"

class MyServerCallbacks: public BLEServerCallbacks
{
  void onConnect(BLEServer* pServer)
  {
    _deviceConnected = true;
  };

  void onDisconnect(BLEServer* pServer)
  {
    _deviceConnected = false;
  }
};

void app_main()
{
  #if defined(CONFIG_BLUEDROID_ENABLED)
  ; // Ensures that libararies are loaded
  #endif

  //// Serial.begin(115200);

  // Create the BLE Device
  BLEDevice::init("ESP32");

  // Create the BLE Server
  _server = BLEDevice::createServer();
  _server->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *_service = _server->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  _characteristic = _service->createCharacteristic(
                      CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );

  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  _characteristic->addDescriptor(new BLE2902());

  // Start the service
  _service->start();

  // Start advertising
  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->setScanResponse(false);
  advertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();

  //// Serial.println("Waiting a client connection to notify...");
}

void LifetimeLoop()
{
  // notify changed value
  if (_deviceConnected)
  {
    _characteristic->setValue((uint8_t*)&_value, 4);
    _characteristic->notify();
    _value++;

    Delay(3); // bluetooth stack will go into congestion, if too many packets are sent, in 6 hours test i was able to go as low as 3ms
}

  // OnDisconnecting
  if (!_deviceConnected && _oldDeviceConnected)
  {
    Delay(500); // give the bluetooth stack the chance to get things ready
    _server->startAdvertising(); // restart advertising
    //// Serial.println("start advertising");
    _oldDeviceConnected = _deviceConnected;
  }

  // connecting
  if (_deviceConnected && !_oldDeviceConnected)
  {
    // do stuff here on connecting
    _oldDeviceConnected = _deviceConnected;
  }
}

void Delay(uint32_t ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}
