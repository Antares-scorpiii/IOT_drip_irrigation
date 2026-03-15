#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <time.h>
#include "config.h"
#include "sensors.h"

int currentMode = 0; 
bool relayState = false;

int startHour = 0;
int startMin = 0;
int endHour = 0;
int endMin = 0;
float targetVolume = 0.0;
float tempThreshold = 0.0;
bool cycleActive = false;

unsigned long lastUpdate = 0;

BLYNK_WRITE(V0) {
  if (currentMode == 0) {
    relayState = param.asInt();
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);
  }
}

BLYNK_WRITE(V3) { currentMode = param.asInt(); cycleActive = false; }
BLYNK_WRITE(V4) { startHour = param.asInt(); }
BLYNK_WRITE(V5) { startMin = param.asInt(); }
BLYNK_WRITE(V6) { endHour = param.asInt(); }
BLYNK_WRITE(V7) { endMin = param.asInt(); }
BLYNK_WRITE(V8) { targetVolume = param.asFloat(); }
BLYNK_WRITE(V9) { tempThreshold = param.asFloat(); }

void setup() {
  Serial.begin(115200);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  initSensors();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  configTime(0, 0, "pool.ntp.org");
  setenv("TZ", "IST-5:30", 1); 
  tzset();
}

void loop() {
  Blynk.run();
  updateFlow();

  if (millis() - lastUpdate > 2000) {
    float temp = getTemperature();
    Blynk.virtualWrite(V1, totalLiters);
    Blynk.virtualWrite(V2, temp);
    handleLogic(temp);
    lastUpdate = millis();
  }
}

void handleLogic(float currentTemp) {
  time_t now = time(nullptr);
  struct tm* timeinfo = localtime(&now);
  int currentH = timeinfo->tm_hour;
  int currentM = timeinfo->tm_min;

  if (currentMode == 1) { 
    bool inTimeWindow = (currentH > startHour || (currentH == startHour && currentM >= startMin)) &&
                        (currentH < endHour || (currentH == endHour && currentM < endMin));
    setRelay(inTimeWindow);
  } 
  else if (currentMode == 2) { 
    if (currentH == startHour && currentM == startMin && !cycleActive && totalLiters < targetVolume) {
      resetFlowVolume();
      cycleActive = true;
      setRelay(true);
    }
    
    if (cycleActive && totalLiters >= targetVolume) {
      setRelay(false);
      cycleActive = false;
    }
  } 
  else if (currentMode == 3) { 
    if (currentTemp > tempThreshold) {
      setRelay(true);
    } else {
      setRelay(false);
    }
  }
}

void setRelay(bool state) {
  if (relayState != state) {
    relayState = state;
    digitalWrite(RELAY_PIN, relayState ? HIGH : LOW);
    Blynk.virtualWrite(V0, relayState);
  }
}