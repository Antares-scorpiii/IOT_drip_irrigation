# Operational Logic (The 4 Modes)

The ESP8266 controller evaluates the `currentMode` variable every loop to determine how the water valve should behave. You can switch between these modes seamlessly via the Blynk App.

## Mode 0: Manual Control
The simplest mode. The physical relay strictly follows the state of the V0 Switch on your Blynk dashboard. 
* **Use Case:** Spot-watering or testing the system.

## Mode 1: Scheduled Timer
The system connects to `pool.ntp.org` to fetch real-time Indian Standard Time (IST). 
* **Logic:** If the current clock time falls between `Start Time` (V4, V5) and `End Time` (V6, V7), the relay turns ON. Otherwise, it stays OFF.
* **Use Case:** Standard daily watering routines (e.g., watering every morning from 06:00 to 06:30).

## Mode 2: Volume-Limited (Precision)
Instead of relying on time (which fluctuates with water pressure), this mode relies on exact fluid dynamics. 
* **Logic:** At the specified `Start Time`, the valve opens. The YF-S201 sensor begins counting pulses. Once the `Total Liters` matches your `Target Volume` (V8), the valve shuts off automatically.
* **Use Case:** Delivering specific doses of water or liquid fertilizer to sensitive crops.



## Mode 3: Temperature-Triggered (Cooling)
An environmental failsafe mode. 
* **Logic:** The system actively monitors the DS18B20 sensor. If the ambient temperature exceeds your `Temp Threshold` (V9), the water turns ON. Once the area cools down below the threshold, the water shuts OFF.
* **Use Case:** Protecting heat-sensitive plants during peak summer afternoons, or controlling a greenhouse misting system.