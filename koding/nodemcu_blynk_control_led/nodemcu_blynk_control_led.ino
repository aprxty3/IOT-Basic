#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "h44avb1Kw2uiAPbPJJmMXs8spxsV1U_x"; //ganti tulisan dengan Auth Token yang masuk ke email

char ssid[] = "Redmi1"; //ganti tulisan dengan nama wifi
char pass[] = "aryanicosa"; //ganti tulisan dengan password wifi

const int ledPin = 16; //D0

BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // ketika button di blynk di klik/push, maka akan dikirim nilai ke esp8266
  
  if (pinValue == 1){
    Serial.println("Menyala");
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("Padam");
    digitalWrite(ledPin, LOW);
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
}

void loop() {
  Blynk.run();
}
