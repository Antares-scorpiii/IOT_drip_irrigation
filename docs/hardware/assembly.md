# Physical Assembly & Plumbing

Building the electronics is only half the battle. Here is how to integrate the system into your plumbing line.

## Plumbing Sequence
For the most accurate readings and safety, follow this specific order from the tap:

1.  **Main Tap** (Source)
2.  **1/2" Female-to-Female Coupler**
3.  **YF-S201 Flow Sensor** (Note the arrow on the side for flow direction!)
4.  **1/2" Male-to-Male Nipple**
5.  **12V Solenoid Valve** (Note the arrow for flow direction!)
6.  **Drip Irrigation Adapter** (To 16mm or 12mm drip pipe)



## Housing the Electronics
Since this will be near water:
* Use an **IP65 rated Junction Box**.
* Drill holes at the **bottom** of the box for wires to exit; this prevents rain from running down the wires into the box (Drip Loop).
* Mount the DS18B20 probe outside the box, but keep the NodeMCU inside for Wi-Fi signal stability.

## Flow Sensor Calibration
The code uses `7.5` as the calibration factor. However, every sensor varies slightly.
1. Run the system in **Manual Mode**.
2. Fill a 1-Liter bottle.
3. Check the Blynk App. If it says `0.9L`, decrease the `7.5` value in `sensors.h`. If it says `1.1L`, increase it.