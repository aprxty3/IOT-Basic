//inialisasi LED
const int led1 = 3;
const int led2 = 4;
const int led3 = 5;
const int led4 = 6;

//inisialisasi button
const int button = 7;
int buttonState = 0;
int buttonValue = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(button, INPUT);
  Serial.begin(9600); //inisialisasi komunikasi serial
  Serial.println("Flip Flop dengan berbagai pola");
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(button);
  if (buttonState == HIGH) {
    buttonValue++;
  }
  if (buttonValue > 5) {
    buttonValue = 0;
  }

  switch (buttonValue) {
    case 1:
      Serial.println("Mode : 1");
      digitalWrite(led1, HIGH); delay(300);
      digitalWrite(led1, LOW); delay(300);
      break;
    case 2:
      Serial.println("Mode : 2");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH); delay(300);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW); delay(300);
      break;
    case 3:
      Serial.println("Mode : 3");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH); delay(300);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW); delay(300);
      break;
    case 4:
      Serial.println("Mode : 4");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH); delay(300);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW); delay(300);
      break;
    case 5:
      Serial.println("Mode : 5");
      digitalWrite(led1, HIGH); delay(100);
      digitalWrite(led2, HIGH); delay(100);
      digitalWrite(led3, HIGH); delay(100);
      digitalWrite(led4, HIGH); delay(100);
      digitalWrite(led1, LOW); digitalWrite(led2, LOW);
      digitalWrite(led3, LOW); digitalWrite(led4, LOW);
      delay(100);
      break;
    default:
      digitalWrite(led1, LOW); digitalWrite(led2, LOW);
      digitalWrite(led4, LOW); digitalWrite(led4, LOW);
  }

}
