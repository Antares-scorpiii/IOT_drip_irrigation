# Components & Selection Criteria

To ensure this project is reproducible in India, we selected parts that are "ruggedized" for heat and widely available on platforms like **Robu.in**, **QuartzComponents**, or **Amazon.in**.

## 1. The Controller: NodeMCU ESP8266
* **Selection:** CP2102 or CH340G variant.
* **Why:** It operates on 3.3V logic but is 5V tolerant on the VIN pin. Built-in Wi-Fi eliminates the need for external modules like the ESP-01.

## 2. Flow Sensor: YF-S201 (1/2" Thread)
* **Specs:** 1-30L/min, 1.75MPa water pressure.
* **Why:** Most Indian household taps and drip irrigation pipes use 1/2 inch (half-inch) standard threading. This sensor screws directly onto a standard CPVC or brass nipple.
* **Selection Detail:** Ensure you get the **Black Plastic** version for standard water; the brass version is unnecessarily expensive for drip systems.

## 3. Temperature Sensor: DS18B20 (Waterproof)
* **Specs:** -55°C to +125°C range.
* **Why:** Unlike the DHT11 (which fails in 80%+ humidity), the DS18B20 is a sealed stainless steel probe.
* **Decision:** We use the **Digital** 1-Wire protocol so we can run long wires (up to 10 meters) from the garden to the controller box without signal loss.

## 4. Solenoid Valve: 12V DC NC Valve
* **Specs:** 1/2 inch, Normally Closed.
* **Selection Detail:** Look for "Gravity Feed" valves if you are using a water tank, or "Pressure Rated" valves if connecting directly to a pressurized tap.
* **Safety:** We chose **Normally Closed (NC)** so that if your house loses power, the valve automatically shuts, preventing a flood.

## 5. Power Strategy
* **The Gap:** You have 12V (Valve) and 5V/3.3V (ESP8266). 
* **Solution:** Use a **12V 2A Power Adapter** as the main source. Use an **LM2596 Buck Converter** to step down that 12V to 5V for the NodeMCU's VIN pin.