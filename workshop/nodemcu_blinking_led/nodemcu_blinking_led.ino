const int ledPin = 16;  //D0
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(115200); // Starts the serial communication  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  Serial.println("Led: Menyala");
  delay(100);

  digitalWrite(ledPin, LOW);
  Serial.println("Led: Padam");
  delay(100);
}
