# Wiring Guide

Proper wiring is critical to ensure accurate sensor readings and to protect the ESP8266 from power surges.

!!! warning "Power Separation"
    Never power the 12V Solenoid Valve directly from the ESP8266. Always use the external 12V power supply routed through the Relay.

## Pin Mapping

| Component | Component Pin | ESP8266 Pin | Notes |
| :--- | :--- | :--- | :--- |
| **Relay** | IN (Signal) | **D1** (GPIO 5) | Active HIGH or LOW depending on relay. |
| **Flow Sensor**| Yellow (Signal) | **D2** (GPIO 4) | Uses hardware interrupts. |
| **DS18B20** | Yellow (Data) | **D3** (GPIO 0) | Requires a 4.7kΩ pull-up resistor. |



## Component-Specific Wiring

### 1. Temperature Sensor (DS18B20)
The DS18B20 uses the 1-Wire protocol. It requires a **4.7kΩ resistor** connecting the Data line (Yellow) to the VCC line (3.3V or 5V). 
!!! failure "Common Error"
    If your Blynk dashboard reads `-127.00°C`, you are missing this resistor or the connection is loose!



### 2. Relay & Solenoid Valve
The relay isolates your low-voltage microcontroller from the high-voltage water valve.
1. Connect ESP8266 `D1` to Relay `IN`.
2. Connect the 12V Power Supply POSITIVE to Relay `COM` (Common).
3. Connect Relay `NO` (Normally Open) to the Solenoid Valve POSITIVE.
4. Connect the 12V Power Supply NEGATIVE directly to the Solenoid Valve NEGATIVE.