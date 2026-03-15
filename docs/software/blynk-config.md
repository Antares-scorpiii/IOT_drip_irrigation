# Blynk Dashboard Setup

The Blynk cloud platform acts as the user interface for this project. You must configure your Virtual Pins (Datastreams) exactly as follows for the code to map correctly.

## Datastream Configuration

Go to your [Blynk Web Console](https://blynk.cloud/), navigate to your Template, and create the following Datastreams under the **Datastreams** tab:

| Virtual Pin | Name | Data Type | Range | Notes |
| :---: | :--- | :--- | :--- | :--- |
| **V0** | Manual Switch | Integer | 0 to 1 | Connect to a Switch widget. |
| **V1** | Water Used | Double | 0 to 1000 | Unit: Liters. Connect to a Value Display. |
| **V2** | Temperature | Double | -10 to 100 | Unit: °C. Connect to a Gauge or Display. |
| **V3** | Operation Mode | Integer | 0 to 3 | 0=Manual, 1=Timer, 2=Volume, 3=Temp. |
| **V4** | Start Hour | Integer | 0 to 23 | Connect to a Step or Numeric Input widget. |
| **V5** | Start Minute | Integer | 0 to 59 | Connect to a Step or Numeric Input widget. |
| **V6** | End Hour | Integer | 0 to 23 | Connect to a Step or Numeric Input widget. |
| **V7** | End Minute | Integer | 0 to 59 | Connect to a Step or Numeric Input widget. |
| **V8** | Target Volume | Double | 0 to 500 | Liters. Trigger for Mode 2. |
| **V9** | Temp Threshold | Double | 0 to 60 | Celsius. Trigger for Mode 3. |

!!! tip "Mobile App Layout"
    Organize your mobile app with the Mode Selector (V3) at the very top. Group your Time inputs (V4-V7) in one row, and your environmental limits (V8, V9) in another to keep the UI clean.