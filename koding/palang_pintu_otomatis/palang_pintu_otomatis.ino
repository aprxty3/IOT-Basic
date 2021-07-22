#include <Servo.h>

// defines pins numbers
const int buzzerPin = 16;  //D0
const int trigPin = 5;  //D1
const int echoPin = 4;  //D2

// defines variables
long duration;
int distance;

Servo myservo;  // create servo object to control a servo

void setup() {
  // put your setup code here, to run once:
  myservo.attach(15);  // attaches the servo on GIO15 to the servo object
  pinMode(buzzerPin, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(115200); // Starts the serial communication

}

void loop() {
  // put your main code here, to run repeatedly:
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

  int pos;

  if (distance < 10) {
    for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 90 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    delay(10000);
    for (pos = 90; pos >= 0; pos -= 1) { // goes from 90 degrees to 0 degrees
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      digitalWrite(buzzerPin, HIGH);
      delay(100);                       // waits 100ms for the servo to reach the position
    }
  } else {
    myservo.write(0);
    digitalWrite(buzzerPin, LOW);
  }

  delay(1000);

}
