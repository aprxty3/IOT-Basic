#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "h44avb1Kw2uiAPbPJJmMXs8spxsV1U_x"; //ganti tulisan dengan Auth Token yang masuk ke email

char ssid[] = "Redmi1"; //ganti tulisan dengan nama wifi
char pass[] = "aryanicosa"; //ganti tulisan dengan password wifi

// defines pins numbers
const int ledPin = 16;  //D0
const int trigPin = 5;  //D1
const int echoPin = 4;  //D2

// defines variables
long duration;
int distance;

BlynkTimer timer;

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

void sendSensor() {
  // start working...
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

}

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  timer.setInterval(1000L, sendSensor);

}

void loop() {
  Blynk.run();
  timer.run();

}
