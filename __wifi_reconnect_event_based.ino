#include <WiFi.h>

const char* ssid = "inGO_basement";
const char* password = "Ingo12345";

void setup() {
  Serial.begin(115200);

  // Connect to WiFi
  connectToWiFi();

  // Additional setup code can be added here
}

void loop() {
  // Your main code here

  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection lost. Reconnecting...");
    connectToWiFi();
  }

  // Additional loop code can be added here
}

void connectToWiFi() {
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 10) {
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(" connected");
  } else {
    Serial.println(" connection failed");
  }
}
