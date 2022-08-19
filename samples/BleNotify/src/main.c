#include <freertos/FreeRTOS.h>   // Include the base FreeRTOS definitions
#include <freertos/task.h>       // Include the task definitions

#include "sdkconfig.h"
#include "..\..\..\src\BLEDevice.h"
#include "..\..\..\src\BLEServer.h"
#include "..\..\..\src\BLEUtils.h"

// BLEServer* _bleServer = NULL;

void app_main()
{
  ;

  #if defined(CONFIG_BLUEDROID_ENABLED)
  ; // Do stuff and things here
  #endif
}
