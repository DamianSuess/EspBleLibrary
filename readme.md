# ESP32 BLE Library based on Arduino

Quickly implement Bluetooth LE on ESP32 using the ESP-IDF FreeRTOS projects.

## Overview

The ESP32 BLE Library is based on the Arduino implementation so that you can quickly implement BLE on your FreeRTOS projects without having to use the Arduino library.

## Coding Standards

Though this is still a "WiP", the library still needs to go through the Xeno Innovations coding standards and naming conventions.

Quick sample:

```cpp
// Parts of a class
class PascalCaseClass
{
  public:
    PascalCaseMethods();
    AnotherMethod(int camelCaseArgs);

  private:
    _privateFields;
}
```

## Sponsor Note

Made with ❤ by, [Xeno Innovations](https://github.com/xenoinc) and [Suess Labs](https://github.com/SuessLabs)

```text
                      `.---.`             ``.---.
                 `:ohmmNNNNNmho.     `-+osysoo+oyh:
               .ohyo/:---:+ymNNm+ `/shy+:.`     .dm`
             `+h+-`         .+dNNhhs:.          /Nm.
            `ys-             `sNNd.           `oNNo`
           `y+`             /hsdNh`         `+dNd+`
           os`            .hh:`yNo       `:ymNh+.
          .h-            /ms. `dd-  `./ohmdy+-`
          :y`        ```+Nh:-:oNhosyyys+/-`
         `+h/+oo-..    ydNmysosms:-..`
     `:osyhd+/::--...`.dNo` :d/`         .`
   `+hs:-`-h`         /NN+`oh:           s:
  `yd:`   `+`         sNNhhs-           `d-
  /Ns                 oNNm/`            oy`
  +Nm/`            `-ohmNNh.          `oh-
  -hNNdo:.`````.:+ydy/.:dNNNs-`     `/yo.
   .smNNNNNNNNNNmy+-`   .smNNNNdhyyhh+-
     `:+ossso+:-`         `:+syyyo/-`
```

## References

The project is based on the works by NKolban's [ESP32_BLE_Arduino](https://github.com/nkolban/ESP32_BLE_Arduino) project and [Bluefruit](https://github.com/adafruit/Adafruit_nRF52_Arduino/tree/master/libraries/Bluefruit52Lib)

Further resources can be found below:

* [Arduino ESP32 BLE Library](https://github.com/espressif/arduino-esp32/tree/master/libraries/BLE)
* [NKolban ESP32 Snippets](https://github.com/nkolban/esp32-snippets)
* [Arduino BLE Library](https://github.com/arduino-libraries/ArduinoBLE)