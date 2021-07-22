const int analogPin = A0;  // Pin ADC0 = A0
int sensorValue = 0;  // value read from the pot

const int buzzerPin = 13; //pin D7
const int ledPin = 15; //pin D8

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the analog in value
  sensorValue = analogRead(analogPin);
  // print the readings in the Serial Monitor
  Serial.println("sensor = " + sensorValue);

  if (sensorValue >= 512) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Led Menyala");
  } else if (sensorValue >= 768){
    digitalWrite(ledPin, HIGH);
    Serial.println("Led Menyala");
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Buzzer bersuara");
  } else {
    digitalWrite(ledPin, HIGH);
    Serial.println("Led Padam");
    digitalWrite(buzzerPin, HIGH);
    Serial.println("Buzzer tidak bersuara");
  }
  
  Serial.println("====================");
  delay(1000);

}
