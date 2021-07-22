#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
BlynkTimer timer;

char auth[] = "auth_token_dari_email"; //ganti tulisan dengan Auth Token yang masuk ke email
char ssid[] = "namaWifi"; //ganti tulisan dengan nama wifi
char pass[] = "passwordWifi"; //ganti tulisan dengan password wifi

const int relayPin = 16; //D0
const int trigPin = 5;  //D1
const int echoPin = 4;  //D2

// defines variables
long duration;
int distance;

BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // ketika button di blynk di klik/push, maka akan dikirim nilai ke esp8266

  if (pinValue == 1) {
    Serial.println("Pompa Menyala");
    digitalWrite(relayPin, LOW);
  } else {
    Serial.println("Pompa Padam");
    digitalWrite(relayPin, HIGH);
  }
}

void sendSensor() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Jarak: ");
  Serial.println(distance);

  Blynk.virtualWrite(V2, distance);

  if (distance <= 10) {
    Blynk.notify("Air tersisa sedikit lagi, nyalakan Pompa!");
  }

  if (distance >= 50) {
    Serial.println("Pompa Padam");
    digitalWrite(relayPin, HIGH);
    Blynk.notify("Pompa dipadamkan otomatis");
    Blynk.virtualWrite(V1, LOW);
  }
}

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); //Matikan Relay, Relay akan aktif ketika sinyal LOW
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  timer.setInterval(5000L, sendSensor); //baca kondisi air dalam bak setiap 5 detik
}

void loop() {
  Blynk.run();
  timer.run();
}
