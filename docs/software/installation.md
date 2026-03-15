# Firmware Installation

Follow these steps to flash the firmware onto your NodeMCU ESP8266.

## Prerequisites

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Add the ESP8266 board package:
    * Go to **File > Preferences**.
    * Paste `http://arduino.esp8266.com/stable/package_esp8266com_index.json` into the *Additional Boards Manager URLs* field.
    * Go to **Tools > Board > Boards Manager**, search for `esp8266`, and click Install.

## Required Libraries
Open the Arduino IDE, navigate to **Sketch > Include Library > Manage Libraries**, and install the following:
* `Blynk` (by Volodymyr Shymanskyy)
* `DallasTemperature` (by Miles Burton)
* `OneWire` (by Jim Studt)

## Flashing the Device
1. Create a new folder named `IrrigationSystem`.
2. Add the three files from the GitHub repository into this folder:
    * `IrrigationSystem.ino`
    * `config.h`
    * `sensors.h`
3. Open `config.h` and update your credentials:
    ```cpp
    #define BLYNK_TEMPLATE_ID "TMPL_YOUR_ID"
    #define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"
    const char* ssid = "YOUR_WIFI_SSID";
    const char* pass = "YOUR_WIFI_PASSWORD";
    ```
4. Select **NodeMCU 1.0 (ESP-12E Module)** from the Boards menu.
5. Select the correct COM port and click **Upload**.